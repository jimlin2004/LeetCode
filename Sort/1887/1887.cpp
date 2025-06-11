#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    int reductionOperations(vector<int>& nums) 
    {
        /*
            sort(由大到小)完之後
            由於第一大的會變成第二大
            直到變成一
            所以其實就是前面大的數字全部憶起慢慢變小的概念

            所以O(n)少一遍就行了
        */

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
        });

        int res = 0;
        int cnt = 0;

        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) // n - 1一定對，因為一定有1當底
        {
            if (nums[i] == 1)
                break;

            ++cnt;
            if (nums[i] != nums[i + 1])
            {
                res += cnt;
            }
        }

        return res;
    }
};