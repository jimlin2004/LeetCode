#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1000000007;
    int maxValue[105][105];
    int dp[105][105];

    int dir[3][2] = {
        {-1, 0}, {0, -1}, {-1, -1}
    };

    inline bool isValid(int i, int j, int n)
    {
        return (i >= 0) && (i < n) && (j >= 0) && (j < n);
    }

    // 簡單dp而已
    vector<int> pathsWithMaxScore(vector<string>& board)
    {
        int n = board.size();

        memset(maxValue, 0, sizeof(maxValue));
        memset(dp, 0, sizeof(dp));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (board[i][j] == 'X')
                    continue;

                if (board[i][j] == 'S')
                {
                    maxValue[i][j] = 0;
                    dp[i][j] = 1;

                    for (int d = 0; d < 3; ++d)
                    {
                        int ni = i + dir[d][1];
                        int nj = j + dir[d][0];

                        if (isValid(ni, nj, n) && board[ni][nj] != 'X')
                            dp[ni][nj] = 1;
                    }
                }
                else if (board[i][j] == 'E')
                {
                    break;
                }
                else
                {
                    maxValue[i][j] += (board[i][j] - '0');

                    for (int d = 0; d < 3; ++d)
                    {
                        int ni = i + dir[d][1];
                        int nj = j + dir[d][0];

                        if (isValid(ni, nj, n) && board[ni][nj] != 'X')
                        {
                            if (maxValue[i][j] > maxValue[ni][nj])
                            {
                                maxValue[ni][nj] = maxValue[i][j];
                                dp[ni][nj] = dp[i][j];
                            }
                            else if (maxValue[i][j] == maxValue[ni][nj])
                            {
                                dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                            }
                        }
                    }
                } 
            }
        }

        // 路不通
        if (dp[0][0] == 0)
            return {0, 0};

        return {maxValue[0][0], dp[0][0]};
    }
};


int main()
{
    Solution sol;
    vector<string> board = {
        "E11","XXX","11S"
    };
    sol.pathsWithMaxScore(board);

    return 0;
}