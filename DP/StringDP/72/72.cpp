#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

/*
    目標: 修改word1 -> word2
    dp[i][j] -> word1前i個字以及word2前j個字相同時的最小修改步驟數
    if (word1[1] == word2[j])
        dp[i][j] = dp[i - 1][j - 1]
    if (word1[i] != word2[j])
        1. insert: dp[i][j] = dp[i][j - 1] + 1      ex: exe -> exeu
        2. delete: dp[i][j] = dp[i - 1][j] + 1      ex: exeu -> exe
        3. replace: dp[i][j] = dp[i - 1][j - 1] + 1 ex: en -> ex
*/

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, word1.size(), word2.size());
    }

    int solve(const string& s1, const string& s2, int i, int j)
    {
        if (i == 0 && j == 0)
            return 0;
        if (i == 0 && j != 0)
            return dp[i][j] = j;
        if (i != 0 && j == 0)
            return dp[i][j] = i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = solve(s1, s2, i - 1, j - 1);
        return dp[i][j] = min({solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1), solve(s1, s2, i - 1, j - 1)}) + 1;
    }
private:
    int dp[505][505];
};