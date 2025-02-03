#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 簡單題
    // 檢查有幾次發生數值下降
    // 若cnt > 1代表不可能僅透過一次旋轉
    // cnt == 1需要檢查nums[0] 是否 >= nums[n - 1]
    // cnt == 0就是原本就sorted了
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        // 發生下降的次數
        int cnt = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
                ++cnt;
        }
        if (cnt > 1)
            return false;
        if (cnt == 1)
            return nums[0] >= nums[n - 1];
        return true;
    }
};