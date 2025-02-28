#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    static const int maxn = 1005;

    /*
        概念跟LCS很像(但不是，只是轉移式很像)
        要建構一個最短的supersequence包含str1與str2(都是subsequence)
        因為要最短，所以基本上一定是從str1與str2拿元素出來，
        不會生新的字，也不會重複用，
        因此最簡單的方法就是
        if (str1[i] == str2[j])
            res += str1[i]; // 因為這個字可以共用
        else
            res += str1[i]或str2[j] // 試試看哪個最短
        用遞迴的時間太久，所以需要dp
        定義dp[i][j] = len代表 (為了方便，dp往右下移一格)
        建構出來的supersequence已經包含str1[1 ~ i]與str2[1 ~ j]且長度為len
        (str1[1 ~ i]代表str1的第1個字到第j個字)
        這樣的定義可以簡單地想出轉移式
        if (str1[i - 1] == str2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        也就是試試看用str1[i - 1]還是str2[j - 1]比較好

        得到dp[][]後再從dp[m][n]一路往回建構出真正的supersequence
        然後記得要reverse
        即為答案
    */

    string shortestCommonSupersequence(string str1, string str2) 
    {
        int dp[maxn][maxn];

        int m = str1.size();
        int n = str2.size();
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }

        string res = "";
        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                res += str1[i - 1];
                --i, --j;
            }
            else if (dp[i - 1][j] < dp[i][j - 1])
            {
                res += str1[i - 1];
                --i;
            }
            else
            {
                res += str2[j - 1];
                --j;
            }
        }

        while (i > 0)
        {
            res += str1[i - 1];
            --i;
        }
        while (j > 0)
        {
            res += str2[j - 1];
            --j;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};