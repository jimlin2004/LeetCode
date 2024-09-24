class Solution {
public:
    bool divisorGame(int n) {
        //dp[i][0 or 1]
        //dp[i][0]代表當數字為i且目前是A的回合時是否會贏
        //dp[i][1]代表當數字為i且目前是B的回合時是否會贏
        bool dp[1005][2];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = false;
        dp[1][1] = true;
        dp[2][0] = true;
        dp[2][1] = false;
        dp[3][0] = false;
        dp[3][1] = true;

        for (int i = 4; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                //枚舉能整除i的j
                if (i % j == 0)
                {
                    //若dp[i - j]是對手的回合且他會輸 -> dp[i]我會贏
                    dp[i][0] |= !dp[i - j][1];
                    dp[i][1] |= !dp[i - j][0];
                }
            }
        }

        return dp[n][0];
    }
};