#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int rowCnt[15][15];
    int colCnt[15][15];
    int boxCnt[15][15];

    bool fixed[15][15];

    int m, n;

    inline int toBoxIndex(int i, int j)
    {
        return (i / 3) * 3 + (j / 3);
    }

    bool solve(int i, int j, vector<vector<char>>& board)
    {
        if (j == n) // 修正index
        {
            j = 0;
            ++i;
        }

        if (i == m) // 到底了
            return true;

        if (fixed[i][j]) // 這一格是固定的
        {
            if (solve(i, j + 1, board))
                return true;
            else
                return false;
        }

        int boxIndex = toBoxIndex(i, j);

        for (int num = 1; num <= 9; ++num)
        {
            if (rowCnt[i][num] != 0 || colCnt[j][num] != 0 || boxCnt[boxIndex][num] != 0)
                continue;
            
            // 嘗試看看
            ++rowCnt[i][num];
            ++colCnt[j][num];
            ++boxCnt[boxIndex][num];
            board[i][j] = (char)(num + '0');
            if (solve(i, j + 1, board))
                return true;
            // 退回去
            --rowCnt[i][num];
            --colCnt[j][num];
            --boxCnt[boxIndex][num];
            board[i][j] = '.';
        }

        return false;
    }

    /*
        用backtracking暴搜答案 -> O(9^(m * n))
    */
    void solveSudoku(vector<vector<char>>& board)
    {
        memset(rowCnt, 0, sizeof(rowCnt));
        memset(colCnt, 0, sizeof(colCnt));
        memset(boxCnt, 0, sizeof(boxCnt));
        memset(fixed, 0, sizeof(fixed));

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    ++rowCnt[i][num];
                    ++colCnt[j][num];
                    ++boxCnt[toBoxIndex(i, j)][num];
                    fixed[i][j] = true;
                }
            }
        }

        solve(0, 0, board);
    }
};