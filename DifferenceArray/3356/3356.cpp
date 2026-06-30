#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        基本上能扣就扣
        然後整體是一個區間修改問題
        問只需要前面k個query就能讓array清空的k是多少
        為了加速，改用二分搜k
        然後配合差分陣列優化檢查答案的過程
    */

    // 差分陣列
    int diff[100005];

    bool check(int k, const vector<int>& nums, const vector<vector<int>>& queries)
    {
        // 用差分陣列處理多次區間減法
        memset(diff, 0, sizeof(diff));

        for (int i = 0; i < k; ++i)
        {
            // 這裡是區間減法
            diff[queries[i][0]] -= queries[i][2];
            diff[queries[i][1] + 1] += queries[i][2];
        }

        // O(n)重建出結果
        int currAdd = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            currAdd += diff[i];
            if (nums[i] + currAdd > 0)
                return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        // 如果已經都是0，就回傳0
        if (all_of(nums.begin(), nums.end(), [](int val){
            return val == 0;
        }))
            return 0;

        // 二分搜k
        int l = 0, r = queries.size() + 1;
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, nums, queries))
                r = mid;
            else
                l = mid;
        }

        // 答案在r
        return (r > queries.size()) ? -1 : r;
    }
};

int main()
{
    vector<vector<int>> qs = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    vector<int> nums = {2, 0, 2};
    Solution S;
    S.minZeroArray(nums, qs);

    return 0;
}