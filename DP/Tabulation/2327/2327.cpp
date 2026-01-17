#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// class Solution
// {
// public:
//     /*
//         O(n ^ 2)
//         dp[i][j] -> 在第i天時有dp[i][j]個人已經知道j天了
//         轉移式看下方
//     */
//     int dp[1005][1005];

//     int peopleAwareOfSecret(int n, int delay, int forget)
//     {
//         memset(dp, 0, sizeof(dp));

//         dp[1][1] = 1;
//         for (int i = 2; i <= n; ++i)
//         {
//             // 每個人都多知道一天
//             // if (j > 1)
//             //     dp[i][j] = dp[i - 1][j - 1]
//             for (int j = 2; j <= i; ++j)
//             {
//                 dp[i][j] = dp[i - 1][j - 1];
//             }

//             // 計算多少人剛知道
//             if (i > delay)
//             {
//                 // 要累加所有前一天中所有 j in [delay, forget - 1]的人
//                 // 都會多告訴一個人
//                 for (int j = delay; j < forget; ++j)
//                 {
//                     dp[i][1] += dp[i - 1][j];
//                     dp[i][1] %= MOD;
//                 }
//             }
//         }

//         // 計算第n天時還記的人有多少
//         int res = 0;
//         for (int j = 1; j <= forget; ++j)
//         {
//             res += dp[n][j];
//             res %= MOD;
//         }

//         return res;
//     }
// };


class Solution
{
public:
    /*
        上面版本的維護區間版本，可以少一個迴圈
        O(n)
        dp[i] -> 在第i天時有dp[i]個人知道
        轉移式看下方
    */
    int dp[1005];

    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        memset(dp, 0, sizeof(dp));

        int currShare = 0; // 當前有多少人會分享給別人
        int res = 1; // 目前有多少人還記得(1 for 一開始)

        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (i > delay)
                currShare = (currShare + dp[i - delay]) % MOD;
            if (i > forget)
            {
                // 維護正確的區間訊息
                int currForget = dp[i - forget];
                // 有些人忘記了，不能再分享
                currShare = (currShare - currForget + MOD) % MOD;
                // 有些人忘記了，要移除那些人
                res = (res - currForget + MOD) % MOD;
            }

            dp[i] = currShare;
            res = (res + currShare) % MOD;
        }

        return res;
    }
};


int main()
{
    Solution S;
    S.peopleAwareOfSecret(6, 2, 4);

    return 0;
}