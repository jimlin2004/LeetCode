#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        因為i <= j <= k
        所以可以三個數字都一樣
        然後x ^ x ^ x = x
        且nums包含所有1 ~ n
        所以根本所有1 ~ n都是做得出來的
        另外0也一定可以(因為有全部的1 ~ n)
        所以當n >= 3，答案至少有n + 1
        但是不只這樣
        因為比如[1, 2, 3, 4]
        可以用1 ^ 2 ^ 4得到7
        因為nums有1 ~ n，當有一個數字的MSB領頭
        後面的bit總能找到方法將後面全部填滿
        因此答案就是< n的2進位全部bit都是1個數字 + 1 (0)
    */
    int uniqueXorTriplets(vector<int>& nums)
    {
        if (nums.size() == 1)
            return 1;
        if (nums.size() == 2)
            return 2; // [1, 2]的case
        int mask = 1;
        while (mask < nums.size())
            mask = (mask << 1) | 1;
        return mask + 1;
    }
};