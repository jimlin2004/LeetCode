#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        題意: 電影院一排有10個座位，4人組只能排在(2, 3, 4, 5), (4, 5, 6, 7), (6, 7, 8, 9)
        問最多能排幾組

        n是row的數量，n很大
        改用reservedSeats處理那些要排的row
        其他空的row都可以排2組
    */
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        sort(reservedSeats.begin(), reservedSeats.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });

        int m = reservedSeats.size();

        int choice1 = 0b0111100000;
        int choice2 = 0b0001111000;
        int choice3 = 0b0000011110;

        int res = 0;

        int processedNumRow = 0;

        for (int i = 0; i < m;)
        {
            int j = i;
            int currRow = 0; // 用bitset處理
            while (j < m && reservedSeats[i][0] == reservedSeats[j][0])
            {
                currRow = currRow | (1 << (reservedSeats[j][1] - 1));
                ++j;
            }
            i = j;
            ++processedNumRow;

            if (((currRow & choice1) == 0) && ((currRow & choice3) == 0))
                res += 2;
            else if (((currRow & choice1) == 0) || ((currRow & choice2) == 0) || ((currRow & choice3) == 0))
                ++res;
        }

        res += (n - processedNumRow) * 2;

        return res;
    }
};