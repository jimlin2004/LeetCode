#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        這題要求最小沒出現的正整數是多少
        看到nums[i]的範圍很大
        但是nums長度是1 ~ n
        所以最小沒出現的正整數只會是 1 ~ n + 1
        因此去枚舉1 ~ n有沒有出現(都有就是n + 1)

        用bool vis[]很好處理
        但是這題要求用O(n)還有空間O(1)

        因此要換一種方式

        解法是借用array的index當作有沒有出現的空間

        先看1有沒有在陣列中，並且負數跟nums[i] > n是我們完全不用的資訊
        因此將他們都換成1(有檢查過1有沒有在array中)

        然後目前剩下的所有數字都是 1 ~ n 的正整數
        從左到右掃描array的時候
        出現的數字就把該數字的index變成負數標記該數字出現過
        然後nums[i] == n的標記在index 0的位置(因為index 0沒用到)

        最後掃描一遍array就知道nums[i] > 0則i就是沒出現的正整數
    */
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();

        bool existsOne = false;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 1)
                existsOne = true;
            else if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }

        if (!existsOne)
            return 1;

        for (int i = 0; i < n; ++i)
        {
            if (abs(nums[i]) == n)
                nums[0] = -abs(nums[0]);
            else
                nums[abs(nums[i])] = -abs(nums[abs(nums[i])]);
        }

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > 0)
                return i;
        }
        // 記得n要後判，因為要求最小沒出現
        if (nums[0] > 0)
            return n;

        return n + 1;
    }
};