#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int price;
    int beauty;
};

class Solution 
{
public:
    // 直接砸線段樹加離散化
    //(其實可以照price排再照beauty排，然後二分搜可以的裡面最右邊的，ㄟ嘿)
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        vector<Item> itemsVec;
        for (auto& vec: items)
            itemsVec.emplace_back(Item{vec[0], vec[1]});
        // 離散化用
        int discreteArray[maxn];
        int len = 0;
        for (Item& item: itemsVec)
        {
            //從1開始放
            discreteArray[len + 1] = item.price;
            ++len;
        }
        sort(discreteArray + 1, discreteArray + 1 + len);
        int m = unique(discreteArray + 1, discreteArray + 1 + len) - (discreteArray + 1);
        memset(ST, 0, sizeof(ST));

        for (Item& item: itemsVec)
        {
            int index = lower_bound(discreteArray + 1, discreteArray + 1 + m, item.price) - discreteArray;
            update(1, 1, m, index, item.beauty);
        }

        vector<int> res;
        for (int q: queries)
        {
            auto it = lower_bound(discreteArray + 1, discreteArray + 1 + m, q);
            int index = it - discreteArray;
            if (*it != q)
                --index;
            if (index == 0)
                res.emplace_back(0);
            else
                res.emplace_back(query(1, 1, m, 1, index));
        }
        return res;
    }
private:
    static const int maxn = 100005;
    int ST[maxn << 2];

    void update(int index, int l, int r, int q, int val)
    {
        if (l == r)
        {
            //存最大的
            if (ST[index] < val)
                ST[index] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (q <= mid)
            update(index * 2, l, mid, q, val);
        else
            update(index * 2 + 1, mid + 1, r, q, val);
        ST[index] = max(ST[index * 2], ST[index * 2 + 1]);
    }

    int query(int index, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return ST[index];
        int mid = (l + r) / 2;
        int res = 0;
        if (ql <= mid)
            res = max(res, query(index * 2, l, mid, ql, qr));
        if (mid < qr)
            res = max(res, query(index * 2 + 1, mid + 1, r, ql ,qr));
        return res;
    }
};

int main()
{
    vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> q = {1,2,3,4,5,6};
    Solution s;
    s.maximumBeauty(items, q);
    return 0;
}