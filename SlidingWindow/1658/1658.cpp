#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        陷阱題:
            每次可以從最左或最右邊拿出數字，求加起來等於x的最少次數
        
        阿其實能夠從最左邊或最右邊拿掉數字
        相當於最後會留下一個連續子陣列
        設nums總和為total，子陣列的windowSum就是total - x
        所以問題從最少加起來等於x變成最長windowLen，windowSum = total - x
    */
    int minOperations(vector<int>& nums, int x) 
    {
        int maxWindowLen = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int windowSum = 0;
        int target = total - x;

        int n = nums.size();

        if (target < 0) // 不可能湊的出來
            return -1;
        if (target == 0) // 全部用上才能剛好
            return n;

        int l = 0, r = 0;
        while (r < n)
        {
            windowSum += nums[r];
            while (l <= r && windowSum > target)
            {
                windowSum -= nums[l];
                ++l;
            }

            if (windowSum == target)
            {
                maxWindowLen = max(maxWindowLen, r - l + 1);
            }

            ++r;
        }

        return (maxWindowLen == 0) ? -1 : n - maxWindowLen;
    }
};