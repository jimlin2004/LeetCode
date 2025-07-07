#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<long long> maximumEvenSplit(long long finalSum) 
    {
        vector<long long> res;
        if (finalSum % 2 != 0)
            return res; // 不可能可以切割
        // 直接從最小的開始嘗試，不斷的2、4、6、8... 一路使用，因為這樣能保證當前和增長速度最慢
        // 最後剩下不能分割的值全部加到最後一個值就行了
        long long curr = 2;
        while (curr <= finalSum)
        {
            res.push_back(curr);
            finalSum -= curr;
            curr += 2;
        }
        if (finalSum != 0) // 還有剩
            res.back() += finalSum;
        return res;
    }
};