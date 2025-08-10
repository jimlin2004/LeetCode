#include <bits/stdc++.h>
using namespace std;


#define maxn 100005

/*
    leetcode 3477的困難版 (n <= 100 -> n <= 1e5)
    ，但由於3477我用一樣的解法，所以複製貼上

    題目只是要找最左邊且 >= fruits[i]的值是否存在
    並且如果存在就要將它刪除
    所以很明顯可以用max 線段樹 + 線段樹上二分搜即可
    可以將O(n ^ 2) -> O(n log n)
*/
class Solution 
{
public:
    int st[maxn << 2];
    int vals[maxn];

    void build(int i, int l, int r)
    {
        if (l == r)
        {
            st[i] = vals[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        st[i] = max(st[i * 2], st[i * 2 + 1]);
    }

    bool queryAndUpdate(int i, int l, int r, int target)
    {
        if (st[i] < target)
            return false;
        
        if (l == r)
        {
            st[i] = 0;
            return true;
        }

        int mid = (l + r) >> 1;
        
        if (target <= st[i * 2])
            queryAndUpdate(i * 2, l, mid, target);
        else
            queryAndUpdate(i * 2 + 1, mid + 1, r, target);
        
        st[i] = max(st[i * 2], st[i * 2 + 1]);

        return true;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = baskets.size();

        for (int i = 0; i < n; ++i)
            vals[i + 1] = baskets[i];
        
        build(1, 1, n);

        int res = 0;

        for (int fruit: fruits)
        {
            if (!queryAndUpdate(1, 1, n, fruit))
                ++res;
        }

        return res;
    }
};