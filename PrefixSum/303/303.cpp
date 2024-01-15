#include <bits/stdc++.h>
using namespace std; 

class NumArray {
public:
    NumArray(vector<int>& nums) 
    {
        int len = nums.size();
        this->prefix_sum[0] = nums[0];
        for (int i = 1; i < len; i++)
            this->prefix_sum[i] = this->prefix_sum[i - 1] + nums[i];
    }
    
    int sumRange(int left, int right) 
    {
        if (left == 0)
            return this->prefix_sum[right];
        return this->prefix_sum[right] - this->prefix_sum[left - 1];
    }
private:
    int prefix_sum[10000];
};