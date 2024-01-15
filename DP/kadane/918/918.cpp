#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
分兩種case
1. 最大的maxSubarraySum頭尾不相連(無環)，此基本的kadane可以解決
2. 最大的maxSubarraySum頭尾不相連(環)，
   觀察Array總total不變，此時最大的maxSubarraySum一定是
   total - minSubarraySum(一定頭尾不相連，否則與maxSubarraySum頭尾相連矛盾)
O(n)
*/

class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int maxSum = INT_MIN;
        int curMaxSum = 0;
        int minSum = INT_MAX;
        int curMinSum = 0;
        int total = 0;
        for (int num: nums)
        {
            curMaxSum = max(curMaxSum + num, num);
            maxSum = max(maxSum, curMaxSum);
            curMinSum = min(curMinSum + num, num);
            minSum = min(curMinSum, minSum);
            total += num;
        }
        if (maxSum <= 0) return maxSum; // 都是負的，就是array中最大的那個
        return max((total - minSum), maxSum);
    }
};