#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 將000...1111..000切成cntVec後簡單搜尋
    int maxActiveSectionsAfterTrade(string s) 
    {
        vector<int> cntVec;
        int currCnt = 1;
        if (s[0] == '1')
            ++currCnt;
        else // 第一個1
            cntVec.emplace_back(1);

        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
                ++currCnt;
            else
            {
                cntVec.emplace_back(currCnt);
                currCnt = 1;
            }
        }
        // 最後的'1'
        if (s.back() == '1')
        {
            cntVec.emplace_back(currCnt + 1);
        }
        else
        {
            cntVec.emplace_back(currCnt);
            //最後的'1'
            cntVec.emplace_back(1);
        }

        int res = 0;

        int totalOne = 0;
        // 不做操作的
        // 偶數i是1的
        for (int i = 0; i < cntVec.size(); i += 2)
        {
            totalOne += cntVec[i];
        }

        res = totalOne;

        // 沒有辦法翻轉的
        if (cntVec.size() < 5)
            return res - 2; // -2 for 去頭去尾

        // 試試看做翻轉的
        // 111...000...111...000...111
        // 所以i = 2是第一個被0包圍的111...
        for (int i = 2; i < cntVec.size() - 2; i += 2)
        {
            //      0000....1111...00000
            //   變 00000...00000.....0000
            // 再變 11111...11111....11111
            res = max(res, totalOne + cntVec[i - 1] + cntVec[i + 1]);
        }

        return res - 2; // -2 for 去頭去尾
    }
};

int main()
{
    string s = "0100";
    Solution sol;
    sol.maxActiveSectionsAfterTrade(s);
    return 0;
}