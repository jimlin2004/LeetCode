#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 統計每個位數有哪幾種數字
    // 然後用統計後的數量相乘加起來就是答案
    long long sumDigitDifferences(vector<int>& nums) 
    {
        vector<vector<long long>> freqs;

        for (int val: nums)
        {
            int i = 0; // 位數
            while (val)
            {
                if (freqs.size() == i) // 位數往後擴
                {
                    freqs.push_back(vector<long long>(10, 0));
                }
                ++freqs[i][val % 10];
                val /= 10;
                ++i;
            }
        }

        long long res = 0;
        for (int i = 0; i < freqs.size(); ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                for (int k = j + 1; k < 10; ++k)
                {
                    res += freqs[i][j] * freqs[i][k];
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution S;
    vector<int> nums = {13, 23, 12};
    S.sumDigitDifferences(nums);

    return 0;
}