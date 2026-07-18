#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int findGCD(vector<int>& nums) 
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        return gcd(minVal, maxVal);
    }
};