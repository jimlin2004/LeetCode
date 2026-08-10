#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        用SG就能解了
        O(n log n)
    */
    inline static int SG[100005];
    inline static bool needInitSG = true;
    int vis[100005];
    /*
        SG(x) = mex{SG(y) | x -> y }
        這題x能轉到x - k，k是完全平方數
        所以
        SG(0) = 0
        SG(1) = mex{SG(0)} = 1
        SG(2) = mex{SG(1)} = 0
        SG(3) = mex{SG(2)} = 1
        SG(4) = mex{SG(0), SG(3)} = 2
        ...
    */
    void buildSG()
    {
        memset(vis, 0, sizeof(vis));
        
        SG[0] = 0;
        for (int i = 1; i < 100005; ++i)
        {
            for (int k = 1; k * k <= i; ++k)
            {
                vis[SG[i - k * k]] = i; // 用i標記，可以省掉memset
            }

            int mex = 0;
            while (vis[mex] == i)
                ++mex;
            SG[i] = mex;
        }
    }

    bool winnerSquareGame(int n) 
    {
        if (needInitSG)
        {
            buildSG();
            needInitSG = false;
        }

        return SG[n] != 0; // 先手必勝
    }
};