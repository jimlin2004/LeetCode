#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        inline int getDigitsSum(int n)
        {
            int res = 0;
            while (n)
            {
                res += n % 10;
                n /= 10;
            }
            return res;
        }

        // 就紀錄一下出現過的digits sum中原數值最大的
        // 並維護最大的答案即可O(n)
        int maximumSum(vector<int>& nums) 
        {
            // 紀錄每個digits sum最大的原數值是多少，-1代表第一次出現
            int maxTable[105];
            memset(maxTable, -1, sizeof(maxTable));

            int res = -0x3f3f3f3f;

            for (int n: nums)
            {
                int digitsSum = getDigitsSum(n);
                if (maxTable[digitsSum] == -1)
                    maxTable[digitsSum] = n;
                else
                {
                    res = max(res, maxTable[digitsSum] + n);
                    maxTable[digitsSum] = max(maxTable[digitsSum], n);
                }
            }

            // 沒有相同digits sum的pair
            // 其實可以將res初始化成-1就行了
            if (res == -0x3f3f3f3f)
                res = -1;
            return res;
        }
};