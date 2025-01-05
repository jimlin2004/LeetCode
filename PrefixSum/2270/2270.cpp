#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //簡單題，直接建完prefix sum後直接枚舉
    int waysToSplitArray(vector<int>& nums) 
    {
        long long prefix[100005];
        prefix[0] = 0;
        int n = nums.size();
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            if (prefix[i] >= (prefix[n] - prefix[i]))
                ++res;
        }
        return res;
    }
};