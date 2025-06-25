#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maxDistance(string s, int k) 
    {
        int res = 0;

        int N = 0, S = 0, W = 0, E = 0;
        
        for (char dir: s)
        {
            if (dir == 'N')
                ++N;
            else if (dir == 'S')
                ++S;
            else if (dir == 'W')
                ++W;
            else
                ++E;

            // 曼哈頓距離可以轉為 |N - S| + |W - E|
            // 所以重點是將水平方向變大以及將垂直方向變大
            // 也就是N、S少的一方變多的一方，W、E少的一方變多的一方
            int change1 = min({N, S, k});
            int change2 = min({W, E, k - change1});

            res = max(res, abs(N - S) + 2 * change1 + abs(W - E) + 2 * change2); // 乘2是為了抵銷少的一方，加到多的一方 
        }

        return res;
    }
};