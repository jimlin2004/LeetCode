#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define maxn 100005

class Solution 
{
public:
    /*
        只要求subsequence的最小值 + 最大值不要超過target
        所以可以sort
        枚舉i時讓nums[i]是最小值，此時只要找到最遠的j同時nums[i] + nums[j] <= target
        符合題意的數量就是pow2[j - i] -> 因為不用算到nums[i]，因為nums[i]一定要在subsequence裡

        底下我的j用二分搜找的 -> O(nlogn)
        但其實可以用雙指標中間相遇
        因為i變大的同時能用的j也會單調變小
        所以可以O(n)找到所有的答案
    */

    int numSubseq(vector<int>& nums, int target) 
    {
        int pow2[maxn];
        pow2[0] = 1;
        for (int i = 1; i < maxn; ++i)
        {
            pow2[i] = (2 * pow2[i - 1]) % MOD;
        }

        int res = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i)
        {
            if (target < nums[i]) // 不用再試了
                break;
            int j = (upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin()) - 1;
            if (j < i) // 不用再試了
                break;
            
            res = (res + pow2[j - i]) % MOD;
        }

        return res;
    }
};