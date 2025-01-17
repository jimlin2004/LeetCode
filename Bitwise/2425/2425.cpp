#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 用XOR的性質減少O(n ^ 2) -> O(n)
    int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        // nums1裡的每一個元素會做m次XOR
        // nums2裡的每一個元素會最n次XOR
        // 偶數次的XOR = 0
        int res = 0;
        if (n & 1)
        {
            for (int val: nums2)
                res ^= val;
        }
        if (m & 1)
        {
            for (int val: nums1)
                res ^= val;
        }
        return res;
    }
};