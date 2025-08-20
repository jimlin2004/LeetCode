#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    /*
        首先dp[i][j][n] = True or False -> matrix[i][j]為右下角的邊長n正方形是否都是1
        可以用dp[i][j][n] = dp[i - 1][j][n - 1] && dp[i][j - 1][n - 1] && dp[i - 1][j - 1][n - 1]得到
        (畫圖想一下跟二維前綴和差不多)
        再來算數量
        1 -> 有1個
        
        1 1
        1 1 -> 有4 + 1 = 5個

        1 1 1
        1 1 1
        1 1 1 -> 有9 + 4 + 1 = 14個

        1 1 1 1
        1 1 1 1
        1 1 1 1
        1 1 1 1 -> 有16 + 9 + 4 + 1 = 30個

        所以對於一個邊長為n的正方形都是1 
        -> 有n ^ 2 + (n - 1) ^ 2 + (n - 2) ^ 2 + ... + 1 ^ 2 = [n * (n + 1) * (2n + 1)] / 6
    
        但是用這樣會有兩個問題
        1. 需要O(n ^ 3)
        2. 會有許多正方形重複計算

        下方程式未完成
    */

    bool dp[305][305][305];

    inline int getSumOfSquare(int n)
    {
        return (n * (n + 1) * (2 * n + 1)) / 6;
    }

    int countSquares(vector<vector<int>>& matrix)
    {
        memset(dp, 0, sizeof(dp));

        int m = matrix.size();
        int n = matrix[0].size();

        int res = 0;

        // dp的i, j往右下偏移一格
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == 1)
                {
                    // 這一格是邊長為1的正方形
                    dp[i][j][1] = true;

                    // 都是1的正方形最大到邊長多少
                    int maxValidK = 1;

                    int maxK = min(i, j);
                    for (int k = 2; k <= maxK; ++k)
                    {
                        dp[i][j][k] = dp[i - 1][j][k - 1] && dp[i][j - 1][k - 1] && dp[i - 1][j - 1][k - 1];

                        if (dp[i][j][k])
                            ++maxValidK;
                        else
                            break;
                    }

                    // 這裡會有許多重複計算
                    res += getSumOfSquare(maxValidK);
                }
            }
        }

        return res;
    }
};



class Solution 
{
public:
    int dp[305][305]; // dp[i][j] -> 以i, j為右下角的最大正方形邊長

    /*
        這裡有O(n ^ 2)的做法，而且能夠不會重複計算

        ? ? ? ? ?
        ?       ?
        ?       ?
        ?       ?
        ? ? ? ? (i, j)
        如果能夠組成邊長n的正方形
        (i, j)的鄰居(i - 1, j), (i, j - 1), (i - 1, j - 1)必須都是邊長(n - 1)的正方形
        也就是說
        (i - 1, j)決定垂直高度
        (i, j - 1)決定水平長度
        (i - 1, j - 1)決定對角線長度
        所以(i, j)能夠組成的正方形瓶頸在於鄰居中長度最小的
        所以轉移式為
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

        然後每個dp[i][j] = k也就是代表
        以(i, j)為右下角的正方形為答案貢獻邊長為1, 2, 3, ..., k的正方形各一個
        所以最後答案就是sum of all dp[i][j]
    */

    int countSquares(vector<vector<int>>& matrix) 
    {
        memset(dp, 0, sizeof(dp));

        int m = matrix.size();
        int n = matrix[0].size();

        int res = 0;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == 1)
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            
                res += dp[i][j];
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    Solution S;
    S.countSquares(matrix);

    return 0;
}