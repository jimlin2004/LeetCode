#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    static const int maxn = 1005;

    /*
        原本以為是LIS，但其實不太像
        因為是費氏數列，需要知道前兩個數字
        解法是用二維dp
        定義: dp[i][j]代表以arr[i]與arr[j]為結尾的序列長度
        題目說嚴格上升序列
        所以數值都是唯一的
        轉移式:
            1. dp[i][j] = dp[prev][i] + 1 if prev exists
            2. dp[i][j] = 2
        也就是若存在arr[prev] + arr[i] = arr[j]
        則dp[i][j]可以來自於dp[prev][i] + 1
        prev怎麼找
        方法是因為arr[prev] = arr[j] - arr[i] (費氏數列)
        只要知道在i之前有沒有prev
        最簡單的方法就是用hash map
        紀錄數值轉index
        更進階可以把找prev的子問題變two sum problem用雙指標法
        若prev不存在
        dp[i][j]直接等於2(嘗試當作費氏子序列的開頭)
        但若最後答案 <= 2
        代表不存在真正的費氏子序列，要return 0
    */
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int dp[maxn][maxn];
        dp[0][0] = 0;

        unordered_map<int, int> valueToIndex;

        valueToIndex[arr[0]] = 0;
        int n = arr.size();
        int res = 0;
        for (int j = 1; j < n; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                auto prevIndexPtr = valueToIndex.find(arr[j] - arr[i]);
                if ((prevIndexPtr != valueToIndex.end()) && (prevIndexPtr->second < i))
                    dp[i][j] = dp[prevIndexPtr->second][i] + 1;
                else
                    dp[i][j] = 2;
                
                res = max(res, dp[i][j]);
            }
            valueToIndex[arr[j]] = j;
        }
        if (res <= 2) // 沒有符合費氏數列的子序列
            return 0;
        return res;
    }
};


int main()
{
    Solution S;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    S.lenLongestFibSubseq(arr);
    return 0;
}