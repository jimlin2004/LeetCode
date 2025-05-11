#include <bits/stdc++.h>
using namespace std;

// 開到3倍是因為allVals會需要一次丟3個
#define maxn 300005
#define lowbit(i) (i & -i)

class Solution 
{
public:
    long long BIT[maxn];
    long long prefix[maxn];

    void update(int x, long long c)
    {
        int i = x;
        while (i < maxn)
        {
            BIT[i] += c;
            i += lowbit(i);
        }
    }

    long long getSum(int x)
    {
        int i = x;
        long long res = 0;
        while (i > 0)
        {
            res += BIT[i];
            i -= lowbit(i);
        }

        return res;
    }

    long long rangeSum(int a, int b)
    {
        return getSum(b) - getSum(a - 1);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        int n = nums.size();

        vector<long long> allVals;

        prefix[0] = 0;
        // prefix[0]也要加入，是因為 prefix[0] = 0 是 第一筆資料前的空前綴，是合法的子陣列開頭
        // 例如若 prefix[1] = -2，prefix[1] - prefix[0] = -2 - 0 = -2，是合法答案，因為在區間 [-2, 2]
        allVals.push_back(prefix[0]);
        allVals.push_back(prefix[0] - lower);
        allVals.push_back(prefix[0] - upper);

        for (int i = 0; i < n; ++i)
        {
            prefix[i + 1] = prefix[i] + nums[i];
            allVals.push_back(prefix[i + 1]);
            allVals.push_back(prefix[i + 1] - lower);
            allVals.push_back(prefix[i + 1] - upper);
        }

        // 離散化allVals到index空間
        sort(allVals.begin(), allVals.end());
        int m = unique(allVals.begin(), allVals.end()) - allVals.begin();

        // 目標找到 lower <= prefix[i] - prefix[j] <= upper
        // 移項: prefix[j] <= prefix[i] - lower 且 prefix[i] - upper <= prefix[j]
        // 所以固定枚舉i的情況下
        // 只要能快速找出有多少個prefix[j]滿足 [prefix[i] - upper, prefix[i] - lower]
        // 很明顯這裡還需要另一個區間查找的功能，由於枚舉prefix[i]時區間會需要修改，所以用BIT
        long long res = 0;
        for (int i = 0; i <= n; ++i)
        {
            int lowerIndex = lower_bound(allVals.begin(), allVals.begin() + m, prefix[i] - upper) - allVals.begin();
            int upperIndex = lower_bound(allVals.begin(), allVals.begin() + m, prefix[i] - lower) - allVals.begin();

            res += rangeSum(lowerIndex + 1, upperIndex + 1);

            int currIndex = lower_bound(allVals.begin(), allVals.begin() + m, prefix[i]) - allVals.begin();
            update(currIndex + 1, 1);
        }

        return res;
    }
};


int main()
{
    vector<int> nums = {-2,5,-1};
    int lower = -2;
    int upper = 2;
    Solution S;
    S.countRangeSum(nums, lower, upper);
}