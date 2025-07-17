#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 枚舉所有可能的4種序列回傳最長的就是答案了
    int maximumLength(vector<int>& nums) 
    {
        int allZero = 0; // 全部都是0
        int allOne = 0; // 全部都是1
        int allDiffStartFromZero = 0; // 全部不一樣(起點是0)
        int allDiffStartFromOne = 0; // 全部不一樣(起點是1)

        int lastDiffStartFromZero = 1;
        int lastDiffStartFromOne = 0;

        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            int curr = nums[i] % 2;
            if (curr == 0)
            {
                ++allZero;
                if (curr != lastDiffStartFromZero)
                {
                    lastDiffStartFromZero = curr;
                    ++allDiffStartFromZero;
                }

                if (curr != lastDiffStartFromOne)
                {
                    lastDiffStartFromOne = curr;
                    ++allDiffStartFromOne;
                }
            }
            else // curr == 1
            {
                ++allOne;
                if (curr != lastDiffStartFromZero)
                {
                    lastDiffStartFromZero = curr;
                    ++allDiffStartFromZero;
                }

                if (curr != lastDiffStartFromOne)
                {
                    lastDiffStartFromOne = curr;
                    ++allDiffStartFromOne;
                }
            }
        }

        return max({allZero, allOne, allDiffStartFromZero, allDiffStartFromOne});
    }
};