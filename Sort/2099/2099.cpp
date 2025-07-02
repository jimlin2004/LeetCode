#include <bits/stdc++.h>
using namespace std;


struct Item
{
    int val;
    int id;
};


class Solution 
{
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        vector<Item> items;
        for (int i = 0; i < nums.size(); ++i)
            items.push_back({nums[i], i});

        sort(items.begin(), items.end(), [](Item& a, Item& b) {
            return a.val > b.val; // 由大到小
        });

        // 前k個照id排
        sort(items.begin(), items.begin() + k, [](Item& a, Item& b) {
            return a.id < b.id;
        });

        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.emplace_back(items[i].val);
        return res;
    }
};