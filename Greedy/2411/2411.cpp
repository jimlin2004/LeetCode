#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        因為要or起來最大
        所以對於每個start i而言
        只要當前的nums[i]的第j個bit是0
        此時i後面的某個nums[]有bit j時subarray就會需要包含到那個nums[]
        如此or起來才會最大

        因此要做的事情就是找到當前nums[i]沒有的bit j
        然後早到離i最近的哪個nums[]有bit j
        答案就是最遠要包含到哪個nums[]時subarray才不會有新的bit更新成1

        O(n * 32)
    */
    vector<int> smallestSubarrays(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> res(n);

        vector<int> pos(32, -1); // 每個bit在最近的哪個nums[]有

        // 倒著做，才好維護pos
        for (int i = n - 1; i >= 0; --i)
        {
            // 最遠有更新的bit
            int j = i;
            // 枚舉nums[i]當前哪個bit沒有
            for (int bit = 0; bit < 32; ++bit)
            {
                if (!(nums[i] & (1 << bit)))
                {
                    if (pos[bit] != -1) // nums[i]後面有人有
                        j = max(j, pos[bit]);
                }
                else
                {
                    // 更新pos，因為nums[i]有
                    // 且i離nums[i]前面的數字更近
                    pos[bit] = i; 
                }
            }

            res[i] = j - i + 1;
        }

        return res;
    }
};