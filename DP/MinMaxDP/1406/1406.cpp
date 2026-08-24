#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        dp[i] = 石頭以第i個為開頭時的玩家可以贏對手的淨收益
        轉移式:
            dp[i] = max{
                stone[i] - dp[i + 1],
                stone[i] + stone[i + 1] - dp[i + 2],
                stone[i] + stone[i + 1] + stone[i + 2] - dp[i + 3]
            }
        用記憶化搜索會超時，改用dp推表
    */
    // bool vis[50005];
    int dp[50005];

    // int solve(int i, const vector<int>& stoneValue)
    // {
    //     int n = stoneValue.size();

    //     if (i >= n)
    //         return 0;

    //     if (vis[i])
    //         return dp[i];
    //     vis[i] = true;

    //     int choice1 = stoneValue[i] - solve(i + 1, stoneValue);
    //     int choice2 = INT_MIN;
    //     int choice3 = INT_MIN;

    //     if (i + 1 < n)
    //         choice2 = stoneValue[i] + stoneValue[i + 1] - solve(i + 2, stoneValue);
    //     if (i + 2 < n)
    //         choice3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(i + 3, stoneValue);
    //     return dp[i] = max({choice1, choice2, choice3});
    // }

    string stoneGameIII(vector<int>& stoneValue)
    {
        // memset(vis, 0, sizeof(vis));
        memset(dp, 0, sizeof(dp));

        // solve(0, stoneValue);

        int n = stoneValue.size();

        // 從後面算回來
        for (int i = n - 1; i >= 0; --i)
        {
            int choice1 = stoneValue[i] - dp[i + 1];
            int choice2 = INT_MIN;
            int choice3 = INT_MIN;
            if (i + 1 < n)
                choice2 = stoneValue[i] + stoneValue[i + 1] - dp[i + 2];
            if (i + 2 < n)
                choice3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3];
            
            dp[i] = max({choice1, choice2, choice3});
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};

int main()
{
    vector<int> values = {1, 2, 3, 7};
    Solution sol;
    sol.stoneGameIII(values);
}