#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:

    /*
        想一下可以知道原本的nums是可以排序的
        然後可以排序就變成可以用freqs[]
        之後枚舉所有的答案
        也就是freqs我們要分三段
        枚舉中間的數字freqs[i]
        left記著freqs[i]之前有多少種數字
        right記著freqs[i]後有多少種數字
        用left * freqs[i] * right算答案
        然後每次要維護left跟right
        這樣可以從O(n ^ 3)壓到O(n)
    */
    int unequalTriplets(vector<int>& nums) 
    {
        unordered_map<int, int> freqs;
        for (int val: nums)
            ++freqs[val];
        
        int res = 0;
        int left = 0, right = nums.size(); // 全部種類
        for (auto& p: freqs)
        {
            right -= p.second;
            res += left * p.second * right;
            left += p.second;
        }

        return res;
    }
};