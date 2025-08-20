#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:

    static constexpr double eps = 1e-5;

    // 回傳兩個數字所有可能的計算結果
    inline vector<double> getAllPossible(double a, double b)
    {
        vector<double> possible = {a + b, a * b, a - b, b - a};
        if (a != 0)
            possible.emplace_back(b / a);
        if (b != 0)
            possible.emplace_back(a / b);
        return possible;
    }

    bool dfs(vector<double>& nums)
    {
        // 剩下一個數字
        if (nums.size() == 1)
        {
            return fabs(nums[0] - 24.0) < eps;
        }

        // 暴力枚舉任意兩個數字做運算(所以與原本nums順序無關)
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                vector<double> nextNums; // 下一次的nums
                // 獲得nums[i], nums[j]可能的計算結果
                for (double res: getAllPossible(nums[i], nums[j]))
                {
                    nextNums.clear();
                    nextNums.emplace_back(res);
                    // 將剩下沒有用來計算的值放到nextNums繼續枚舉
                    for (int k = 0; k < nums.size(); ++k)
                    {
                        if (k != i && k != j)
                            nextNums.emplace_back(nums[k]);
                    }

                    if (dfs(nextNums))
                        return true;
                }
            }
        }

        return false;
    }

    /*
        cards的順序不重要，都要枚舉
        然後交給dfs暴力枚舉
    */
    bool judgePoint24(vector<int>& cards)
    {
        vector<double> nums(cards.begin(), cards.end());

        return dfs(nums);
    }
};