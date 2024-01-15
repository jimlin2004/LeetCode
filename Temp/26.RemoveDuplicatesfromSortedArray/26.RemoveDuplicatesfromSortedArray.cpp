#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int temp = -9999;
        sort(nums.begin(), nums.end());
        for (auto it = nums.begin(); it != nums.end();)
        {
            if (*it == temp)
                it = nums.erase(it);
            else
            {
                temp = *it;
                it++;
            }
        }
        return nums.size();
    }
};