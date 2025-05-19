#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    unordered_map<int, long long> cnt; // cnt數每個數字出現幾次

    long long countGood(vector<int>& nums, int k) 
    {
        int n = nums.size();

        int l = 0, r = 0;

        long long window = 0; // 當前窗口有多少pair

        long long res = 0;

        while (l <= r && r < n)
        {
            ++cnt[nums[r]];
            window += cnt[nums[r]] - 1; // -1 for 只有一個不算pair
            
            while (window >= k)
            {
                res += (n - r); // 當[l, r]有至少k個pair，則一路到底都至少有k個pair，總共有n - r個subarray
                
                // 開始減少l，這樣找到的答案才沒有重複計算(因為左邊界每次不一樣)
                window -= (cnt[nums[l]] - 1); // -1 for 只有一個不算pair
                --cnt[nums[l]];
                ++l;
            }
            
            ++r;
        }

        return res;
    }
};


int main()
{
    vector<int> nums = {1,1,1,1,1};
    Solution S;
    S.countGood(nums, 10);

    return 0;
}