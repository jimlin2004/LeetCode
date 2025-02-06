#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 需要離散化
    unordered_map<int, int> cnt;

    // 重點: 數字都不一樣，所以可以用統計數字的
    int tupleSameProduct(vector<int>& nums) 
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                ++cnt[nums[i] * nums[j]];
            }
        }

        int res = 0;
        for (auto& p: cnt)
        {
            if (p.second > 1)
            {
                // 這裡要推一下數學，兩個pair可以互換，pair裡又能互換
                // C(p.second, 2) * 8
                res += (p.second * (p.second - 1)) * 4;
            }
        }
        return res;
    }
};