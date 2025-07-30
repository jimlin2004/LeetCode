#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 處理一下最靠近且不相同的左右鄰居即可
    int countHillValley(vector<int>& nums)
    {
        int n = nums.size();
        
        // 左邊的鄰居
        vector<int> left(n + 5, 0);
        // 右邊的鄰居
        vector<int> right(n + 5, 0);

        left[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (nums[i - 1] == nums[i])
                left[i] = left[i - 1];
            else
                left[i] = nums[i - 1];
        }

        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i + 1] == nums[i])
                right[i] = right[i + 1];
            else
                right[i] = nums[i + 1];
        }

        int res = 0;

        for (int i = 1; i < n - 1; ++i)
        {                                                     // 避免重複計算
            if (left[i] < nums[i] && nums[i] > right[i] && (i == 1 || nums[i - 1] != nums[i]))
                ++res;                                        // 避免重複計算
            else if (left[i] > nums[i] && nums[i] < right[i] && (i == 1 || nums[i - 1] != nums[i]))
                ++res;
        }

        return res;
    }
};