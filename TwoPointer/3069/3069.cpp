#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 考點只有要in place的時候怎麼處理
    vector<int> resultArray(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> res(n, 0);
        int leftPtr = 0; // arr1的結尾
        int rightPtr = n - 1; // arr2的結尾

        res[leftPtr] = nums[0];
        res[rightPtr] = nums[1];

        for (int i = 2; i < n; ++i)
        {
            if (res[leftPtr] >= res[rightPtr])
            {
                res[++leftPtr] = nums[i];
            }
            else
            {
                res[--rightPtr] = nums[i];
            }
        }

        // 這時候後半段是反的，所以要返回來
        reverse(res.begin() + rightPtr, res.end());

        return res;
    }
};