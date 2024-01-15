#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        for (int n: nums)
        {
            if (table.find(n) == table.end())
                table[n] = true;
            else
                return true;
        }
        return false;
    }
    unordered_map<int, bool> table;
};