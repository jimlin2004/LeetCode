#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:

    bool check(int nums[], int size)
    {
        static int cnt[10];
        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < size; ++i)
        {
            if (cnt[nums[i]] != 0)
                return false;
            ++cnt[nums[i]];
        }

        return true;
    }

    // 實作一遍就結束了
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int m = 0;
        int nums[9];

        // 橫的
        for (int i = 0; i < 9; ++i)
        {
            m = 0;
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                    nums[m++] = board[i][j] - '0';
            }

            if (!check(nums, m))
                return false;
        }

        // 直的
        for (int j = 0; j < 9; ++j)
        {
            m = 0;
            for (int i = 0; i < 9; ++i)
            {
                if (board[i][j] != '.')
                    nums[m++] = board[i][j] - '0';
            }

            if (!check(nums, m))
                return false;
        }

        // 方塊
        int ti = 0, tj = 0; //左上角座標
        while (!(ti == 9 && tj == 9))
        {
            if (tj == 9)
                tj = 0;

            m = 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (board[ti + i][tj + j] != '.')
                        nums[m++] = board[ti + i][tj + j] - '0';
                }
            }

            if (!check(nums, m))
                return false;
            
            tj += 3;
            if (tj == 9)
                ti += 3;
        }

        return true;
    }
};