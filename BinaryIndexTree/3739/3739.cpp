#include <bits/stdc++.h>
using namespace std;


/*
    概念是將nums中數值等於target的設為1，其他設為-1
    此時如果subarray的總和 > 0就代表該subarray的眾數就是target
    
    加入prefixSum就能知道當前的總和

    所以問題變成要找到l < r 且 (prefix[r] - prefix[l - 1] > 0)的pair有幾個
    問題等價於找l < r 且 prefix[r] > prefix[l - 1]的pair有幾個

    目前這樣還是O(n^2)
    因為每次都是r往前找有幾個l符合
    想到使用BIT維護比當前prefixSum數值小的有多少
    且更新BIT的值
    這樣就可以變成O(n log n)

    另外BIT要開多大，因為問題變成每次只會 +1/-1
    所以prefixSum的值域就是[-n, n]
    因此BIT就是開兩倍n
    同時為了處理負數，在使用BIT時要使用offset (n + 1)的方式
    (+1 是因為BIT從1開始)

    事實上這題可以用freq array + running sum的技巧做到O(n)
    但套BIT可以少很多思考過程

    細節看下方
*/
class Solution
{
private:
    static constexpr int maxn = 100005;
    int BIT[2 * maxn + 5];

    inline int lowbit(int i)
    {
        return (-i) & i;
    }

    void BIT_add(int i, int c)
    {
        while (i < 2 * maxn + 5)
        {
            BIT[i] += c;
            i += lowbit(i);
        }
    }

    long long BIT_getRangeSum(int i)
    {
        long long res = 0;
        while (i > 0)
        {
            res += BIT[i];
            i -= lowbit(i);
        }
        return res;
    }
public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        memset(BIT, 0, sizeof(BIT));

        int n = nums.size();
        int prefixSum = 0;

        long long res = 0;

        // 一開始prefix = 0要放入BIT中
        // 否則一開始如果prefixSum > 0會回傳0，但其實是一個可以的答案
        BIT_add(0 + n + 1, 1);

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == target)
                ++prefixSum;
            else
                --prefixSum;
            
            // 得到數值 <= prefixSum - 1的共有幾個(因為是要嚴格小於)
            res += BIT_getRangeSum(prefixSum + n + 1 - 1);
            // 更新BIT
            BIT_add(prefixSum + n + 1, 1);
        }

        return res;
    }
};