#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        題意: 只能平移img1，求平移後能讓img1對到img2的最大重疊

        解法: 枚舉img1的所有點作為代表移動到img2的所有點(就像向量平移)，保留最好答案

        實作上可以直接枚舉point pair的相對向量，然後一一平移作比對
        也可以統計相對向量，因為如果一一平移後所有點的相對向量是一樣的
        所以統計point pair的相對向量然後選最大相當於知道一一平移後的最好答案
    */

    int offsetCnts[65][65]; // 用來統計相對向量，開兩倍大小處理平移向量的負數

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        memset(offsetCnts, 0, sizeof(offsetCnts));

        vector<pair<int, int>> p1;
        vector<pair<int, int>> p2;

        int n = img1.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (img1[i][j])
                    p1.emplace_back(i, j);
                if (img2[i][j])
                    p2.emplace_back(i, j);
            }
        }

        int res = 0;

        // 統計相對向量
        for (const auto& [x1, y1]: p1)
        {
            for (const auto& [x2, y2]: p2)
            {
                // + n將負數轉正
                int dx = x2 - x1 + n;
                int dy = y2 - y1 + n;

                res = max(res, ++offsetCnts[dx][dy]);
            }
        }

        return res;
    }
};