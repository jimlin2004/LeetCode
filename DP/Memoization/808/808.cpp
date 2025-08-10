#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    /*
        有點難的題
        難的點不是dp，而是數值範圍

        首先題目的操作都是以25作為單位的
        所以我們將每25視為一個單位

        所以題目輸入n，要當作ceil(n / 25.0)來看(最後可能多一單位，所以用ceil)
        此時就能用dp[i][j] -> A還有i個單位，B還有j個單位

        當i <= 0 && j <= 0時是同時用完，所以dp[i][j] = 0.5
        i <= 0時A先用完，所以dp[i][j] = 1
        j <= 0時B先用完，所以dp[i][j] = 0

        轉移式就是題目給的所有操作
        即dp[i][j] = (dp[i - 4][j] + dp[i - 3][j - 1] + dp[i - 2][j - 2] + dp[i - 1][j - 3]) / 4.0;

        (重點)
        但是一看數字範圍傻了
        n <= 1e-9
        然而這題其實用程式去模擬的話
        你會發現dp[200][200]時答案已經與1個誤差 < 1e-5
        這是由於所有操作中A先用完的可能比較多
        當n越大時答案會越接近1
        所以我們能夠從1算到m
        當中途已經到達誤差範圍內時直接回傳1就行了
    */

    unordered_map<int, unordered_map<int, double>> dp;

    double dfs(int i, int j)
    {
        if (i <= 0 && j <= 0)
            return 0.5; // 同時用完
        if (i <= 0)
            return 1; // A先用完
        if (j <= 0)
            return 0; // B先用完
        
        if (dp[i].count(j))
            return dp[i][j];

        
        return dp[i][j] = (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3)) / 4.0;
    }

    double soupServings(int n) 
    {
        int m = (int)ceil(n / 25.0);

        double eps = 1 - 1e-5;

        for (int k = 1; k <= m; ++k)
        {
            if (dfs(k, k) > eps)
                return 1; // 誤差範圍內了
        }

        return dfs(m, m); // 用dfs()，否則n = 0會錯
    }
};