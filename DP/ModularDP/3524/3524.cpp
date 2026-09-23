#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        題意: 將nums的前綴跟後綴刪掉後，剩下的數值乘積 % k = x的數量有多少?
        注意前綴後綴可以是empty set

        所以這是個騙人的障眼法
        所有前綴後綴可以自由選其實就是說nums中的所有非空subarray
        乘積 % k = x的有多少

        所以就是一個同餘dp
        dp[i][rem] -> 以第i個為結尾時 % k等於rem的subarray有多少個

        轉移式:
        遇到新的數字v時，
        dp[i][v % k] = dp[i - 1][v % k] + 1
        然後其他原本餘數為rem的要轉變
        dp[i][(rem * v) % k] += dp[i - 1][rem]
    
        因為dp[i]只與dp[i - 1]有關，可以滾動優化
    */

    vector<long long> resultArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        vector<long long> res(k, 0);
        dp[0][nums[0] % k] = 1;
        res[nums[0] % k] = 1;
        for (int i = 1; i < n; ++i)
        {
            int v = nums[i] % k;
            for (int rem = 0; rem < k; ++rem)
            {
                dp[i][(rem * v) % k] += dp[i - 1][rem];
            }
            dp[i][v % k] += 1;

            for (int rem = 0; rem < k; ++rem)
            {
                res[rem] += dp[i][rem];
            }
        }

        return res;
    }
};