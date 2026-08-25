#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int missingMultiple(vector<int>& nums, int k) 
    {
        int n = nums.size();

        vector<bool> vis(105, false);

        for (int val: nums)
            vis[val] = true;
        
        int curr = k;

        while (curr < 105 && vis[curr])
            curr += k;
        
        return curr;
    }
};