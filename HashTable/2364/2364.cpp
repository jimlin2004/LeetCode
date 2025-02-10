#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 數學移項題
    // 題目要j - i != nums[j] - nums[i]
    // 移項變成nums[j] - j != nums[i] - i
    // 所以只要用hash去數到j之前有多少個nums[j] - j
    // 也就是有幾個不是bad pair
    // 再將所有j - 不是bad pair加起來即可
    long long countBadPairs(vector<int>& nums) 
    {
        unordered_map<int, long long> cnt;
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; ++i)
        {
            res += i - cnt[nums[i] - i];
            ++cnt[nums[i] - i];
        }
        return res;
    }
};