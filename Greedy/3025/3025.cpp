#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        題目用左上的矩形
        我用右下的矩形去判斷

        將points照x軸排(左到右)再照y軸排(上到下)後
        首先points[i].y >= points[j].y才能是右下矩形

        由於x軸的順序保證
        所以只要維護枚舉的過程中出現過的最高y -> preMaxY
        若當前的points[j].y > preMaxY時
        代表i與j過程中的點都在矩形的下方
        上方的點會在判斷points[i].y >= points[j].y時就過濾完成

        O(n^2 + nlogn)
    */
    int numberOfPairs(vector<vector<int>>& points)
    {
        // 照x軸排(左到右)再照y軸排(上到下)
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int res = 0;

        int n = points.size();
        // 開始枚舉任意兩個點
        for (int i = 0; i < n; ++i)
        {
            int prevMaxY = -0x3f3f3f3f; //枚舉過程的最高點
            for (int j = i + 1; j < n; ++j)
            {
                if (points[i][1] >= points[j][1])
                {
                    if (prevMaxY < points[j][1])
                        ++res;
                    
                    prevMaxY = max(prevMaxY, points[j][1]);
                }
            }
        }

        return res;
    }
};