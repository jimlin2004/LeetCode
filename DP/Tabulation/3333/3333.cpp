#include <bits/stdc++.h>
using namespace std;

#define maxn 500005
#define MOD 1000000007

class Solution 
{
public:
    long long freqs[maxn]; // 字串轉成字元的連續頻率
    /* 
        定義dp[i][j] -> 只用前i個freqs能夠組出長度j有幾種方法
        轉移式:
            dp[i][j] = sum_{j' = 1 ~ freqs[i]} dp[i - 1][j - j']
        到這邊由於n < k -> 所以空間複雜度是O(k ^ 2)
        但是由於dp轉移式需要往回加，所以目前dp的時間複雜度是O(k ^ 3)
        k = 2000會超時
        所以需要額外利用prefix sum g[i][j] = sum_{j' = 1 ~ j} dp[i][j']
        dp轉移式會變成
            dp[i][j] = g[i - 1][j - 1] - g[i - 1][j - 1 - freqs[i]]
        這樣就能夠O(k ^ 2)解決了
    */
    long long dp[2005][2005];
    long long g[2005][2005];

    /*
        作法: 求至少長度k -> 變成所有組合 - 最多長度k - 1
        需要dp + prefix sum優化
    */
    int possibleStringCount(string word, int k) 
    {
        int m = 1; // freqs[]的長度 -> 從1開始
        int n = word.size();

        long long currFreq = 1;
        for (int i = 1; i < n; ++i)
        {
            if (word[i - 1] == word[i])
                ++currFreq;
            else
            {
                freqs[m++] = currFreq;
                currFreq = 1;
            }
        }
        freqs[m++] = currFreq; // 最後一個
        --m; // 讓m回歸freqs[]長度的意思

        long long total = 1; // 所有字串組合可能 -> 整個freq乘起來
        // ex: abbccca -> 1 * 2 * 3 * 1 -> 6種
        for (int i = 1; i <= m; ++i)
            total = (total * freqs[i]) % MOD;

        if (m >= k) // 如果原本freqs.size()就超過k -> 答案就是所有字串組合可能
            return total;

        dp[0][0] = 1;
        for (int j = 0; j < k; ++j)
            g[0][j] = 1;  // 正確的 prefix sum 定義

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j < k; ++j)
            {
                int len = j - 1 - freqs[i];
                if (len >= 0)
                    dp[i][j] = (g[i - 1][j - 1] - g[i - 1][len] + MOD) % MOD;
                else
                    dp[i][j] = g[i - 1][j - 1];
            }

            g[i][0] = dp[i][0];
            for (int j = 1; j < k; ++j)
                g[i][j] = (g[i][j - 1] + dp[i][j]) % MOD;
        }

        return (total - g[m][k - 1] + MOD) % MOD;
    }
};


int main()
{
    Solution S;
    string str = "aabbccdd";
    int k = 7;
    S.possibleStringCount(str, k);
    return 0;
}