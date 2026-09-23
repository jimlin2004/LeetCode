#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int prod;
    int pref_cnts[5];
};

class Solution 
{
public:
    /*
        這題第一題是3524，但其實沒有太大關係

        題意:
        每次查詢
        1. 單點修改: nums[index] = value
        2. 暫時拿掉前綴[0, start - 1] (start = 0代表不拿掉)
        3. 統計所有有多少subarray符合
        end \in [start, n - 1]
        ( prod_(j = start)^{end} nums[j] ) % k = x
        end是代表我可以拿掉所有後綴，考慮所有非空前綴

        完全就是線段樹的形狀

        但是這一題線段樹要保留的狀態要討論
        考慮一個線段樹維護區間[l, r]
        1. 區間總乘積 % k
        2. 非空前綴積的同餘cnt陣列:
        pref_cnts[rem]代表在[l, r]中
        以l為起點的所有前綴中，前綴積 % k = rem的前綴各數

        第一個區間總乘積很好合併
        但是pref_cnts怎麼處理?
        設左子數 tl, 右子樹 tr，當前樹curr
        因為是前綴積，所以左子樹全數繼承
        curr.pref_cnts[rem] = tl.pref_cnts[rem]
        右子樹的要合併上來，變成前綴積
        意味著要乘上左子樹的區間總乘機
        所以轉移為
        curr.pref_cnts[(tl的總乘積 x rem) % k] += tr.pref_cnts[rem]
    */

    Node st[100000 * 4 + 5];

    Node pullup(const Node& lNode, const Node& rNode, int k)
    {
        Node newNode;
        newNode.prod = (lNode.prod * rNode.prod) % k;
        memset(newNode.pref_cnts, 0, sizeof(newNode.pref_cnts));
        for (int rem = 0; rem < k; ++rem)
        {
            newNode.pref_cnts[rem] = lNode.pref_cnts[rem];
        }

        for (int rem = 0; rem < k; ++rem)
        {
            newNode.pref_cnts[(lNode.prod * rem) % k] += rNode.pref_cnts[rem];
        }

        return newNode;
    }

    void build(int i, int l, int r, const vector<int>& nums, int k)
    {
        if (l == r)
        {
            st[i].prod = nums[l] % k;
            memset(st[i].pref_cnts, 0, sizeof(st[i].pref_cnts));
            st[i].pref_cnts[nums[l] % k] = 1;

            return;
        }

        int mid = (l + r) >> 1;
        build(i * 2, l, mid, nums, k);
        build(i * 2 + 1, mid + 1, r, nums, k);

        st[i] = pullup(st[i * 2], st[i * 2 + 1], k);
    }

    void modify(int i, int l, int r, int p, int val, int k)
    {
        if (l == r)
        {
            st[i].prod = val % k;
            memset(st[i].pref_cnts, 0, sizeof(st[i].pref_cnts));
            st[i].pref_cnts[val % k] = 1;

            return;
        }

        int mid = (l + r) >> 1;
        if (p <= mid)
            modify(i * 2, l, mid, p, val, k);
        else
            modify(i * 2 + 1, mid + 1, r, p, val, k);
        st[i] = pullup(st[i * 2], st[i * 2 + 1], k);
    }

    // x是目標rem
    // 但是因為查詢的是前綴積，所以必須要記錄當前左側的累積乘積
    // 能這樣處理是因為我走訪線段的時候是走完左子樹再走右子樹
    int query(int i, int l, int r, int ql, int qr, int x, int k, int& currProd)
    {
        if (ql <= l && r <= qr)
        {
            int res = 0;
            // 找到所有符合(currProd * rem) % k == x的
            for (int rem = 0; rem < k; ++rem)
            {
                    if ((currProd * rem) % k == x)
                        res += st[i].pref_cnts[rem];
            }

            // 更新累積前綴積
            currProd =(currProd * st[i].prod) % k;

            return res;
        }

        int res = 0;

        int mid = (l + r) >> 1;
        if (ql <= mid)
            res += query(i * 2, l, mid, ql, qr, x, k, currProd);
        if (mid < qr)
            res += query(i * 2 + 1, mid + 1, r, ql, qr, x, k, currProd);
        return res;
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) 
    {
        int n = nums.size();

        build(1, 0, n - 1, nums, k);

        int q = queries.size();

        vector<int> res(q, 0);
        for (int i = 0; i < q; ++i)
        {
            modify(1, 0, n - 1, queries[i][0], queries[i][1], k);
            int currProd = 1;
            res[i] = query(1, 0, n - 1, queries[i][2], n - 1, queries[i][3], k, currProd);
        }

        return res;
    }
};