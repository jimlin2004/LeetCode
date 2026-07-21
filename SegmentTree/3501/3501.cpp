#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 線段樹
    vector<int> st;

    void build(int i, int l, int r, vector<int>& vals)
    {
        if (l == r)
        {
            st[i] = vals[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(i * 2, l, mid, vals);
        build(i * 2 + 1, mid + 1, r, vals);
        st[i] = max(st[i * 2], st[i * 2 + 1]);
    }

    int query(int i, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return st[i];
        int maxVal = 0;
        int mid = (l + r) >> 1;
        if (ql <= mid)
            maxVal = max(maxVal, query(i * 2, l, mid, ql, qr));
        if (mid < qr)
            maxVal = max(maxVal, query(i * 2 + 1, mid + 1, r, ql, qr));
        return maxVal;
    }

    /*
        題目要先了解3499的
        然後只是改成只能對[l, r]的區間操作
        答案還是要整體s能有幾個'1'

        做法是切成zeroBlock
        然後二分搜找到要處理的區間
        分段 + 線段樹討論
    */
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) 
    {
        int n = s.size();

        // 切出所有0分段資訊
        vector<int> zeroBlockLeft;
        vector<int> zeroBlockRight;
        vector<int> zeroBlockLen;
        int i = 0;
        while (i < n)
        {
            int start = i;
            while (i < n && s[i] == s[start])
                ++i;
            if (s[start] == '0')
            {
                zeroBlockLeft.emplace_back(start);
                zeroBlockRight.emplace_back(i - 1);
                zeroBlockLen.emplace_back(i - start);
            }
        }

        // 所有的1
        int cntOne = count(s.begin(), s.end(), '1');
        int m = zeroBlockLen.size();
        if (m < 2) // 無法做翻轉
        {
            return vector<int>(queries.size(), cntOne);
        }

        // zeroBlockLen的連續兩個相加
        vector<int> sumTwo(m - 1);
        for (int i = 0; i < m - 1; ++i)
            sumTwo[i] = zeroBlockLen[i] + zeroBlockLen[i + 1];
        
        // 在sumTwo上做線段樹
        st.resize(sumTwo.size() * 4); // 開4倍大小
        build(1, 0, sumTwo.size() - 1, sumTwo);

        vector<int> res;
        for (auto& Q: queries)
        {
            int ql = Q[0];
            int qr = Q[1];
            // 處理邊界
            // 先找到真正的左邊界在第幾個zeroBlock裡
            // 也就是第一個blockRight >= ql的
            int L_i = lower_bound(zeroBlockRight.begin(), zeroBlockRight.end(), ql) - zeroBlockRight.begin();
            // 找到真正的右邊界在第幾個zeroBlock裡
            // 也就是最後一個blockLeft <= qr的
            int R_i = upper_bound(zeroBlockLeft.begin(), zeroBlockLeft.end(), qr) - zeroBlockLeft.begin() - 1;
            if (L_i >= R_i) // 只有0或1個zeroBlock，無法翻轉
            {
                res.emplace_back(cntOne);
                continue;
            }

            // 最左邊實際長度
            int lenL = zeroBlockRight[L_i] - max(zeroBlockLeft[L_i], ql) + 1;
            // 最右邊實際長度
            int lenR = min(zeroBlockRight[R_i], qr) - zeroBlockLeft[R_i] + 1;

            int maxGain = 0;

            if (L_i + 1 == R_i) // 只有兩個zeroBlock
            {
                maxGain = lenL + lenR;
            }
            else
            {
                // 左邊的case(邊界會被卡)
                int case1 = lenL + zeroBlockLen[L_i + 1];
                // 中間的case，用線段樹快速查詢
                int case2 = 0;
                if (L_i + 1 <= R_i - 2)
                    case2 = query(1, 0, sumTwo.size() - 1, L_i + 1, R_i - 2);
                // 右邊的case(邊界會被卡)
                int case3 = lenR + zeroBlockLen[R_i - 1];
                maxGain = max({case1, case2, case3});
            }

            res.emplace_back(cntOne + maxGain);
        }

        return res;
    }
};