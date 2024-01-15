#include <bits/stdc++.h>
using namespace std;

//類似kadane
//原理: 最大值可能是當前最大值乘上正數或負數乘負數得到最大值(此時的負數是當前最小值)
//      要注意當前值比當前最大值大或與當前最小值小的情況，此時捨棄之前從此當前值當作頭
class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int res = nums[0];
        int currentMin = nums[0];
        int currentMax = nums[0];

        int temp;
        for (int i = 1; i < nums.size(); ++i)
        {
            temp = max(nums[i], max(nums[i] * currentMin, nums[i] * currentMax));
            currentMin = min(nums[i], min(nums[i] * currentMin, nums[i] * currentMax));
            currentMax = temp;
            res = max(res, currentMax);
        }
        return res;
    }
};