#include <bits/stdc++.h>
using namespace std;

// struct State
// {
//     int i, j;
//     int mask;
//     int energy;
// };

// class Solution 
// {
// public:
//     // A[i][j][mask][energy] = 最少步數, mask是收集哪些垃圾的狀壓
//     // 要記得用inline static才不會炸空間
//     inline static int A[25][25][(1 << 10) + 5][55];
//     inline static int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//     int m, n;

//     int litterID[25][25];

//     inline bool isValid(int i, int j)
//     {
//         return (i >= 0) && (i < m) && (j >= 0) && (j < n);
//     }

//     /*
//         麻煩的題目，原來leetcode會歸類為medium
//         (暴雷: 帶狀態BFS + 狀壓 + 不能直覺設定state，否則超時)
//         有起點S，有litters L，有R可以回復能量，問最少移動steps
//         所以明顯的就是帶狀態的dijkstra，但因為cost都是1，用BFS就好
//         !!!!!!!這樣會超時，因為A的狀態太多
//         換下面的做法
//     */
//     int minMoves(vector<string>& classroom, int maxEnergy) 
//     {
//         memset(A, 0x3f, sizeof(A));
//         memset(litterID, -1, sizeof(litterID));

//         int si, sj;
//         int litterNum = 0;

//         m = classroom.size();
//         n = classroom[0].size();

//         for (int i = 0; i < m; ++i)
//         {
//             for (int j = 0; j < n; ++j)
//             {
//                 if (classroom[i][j] == 'S')
//                 {
//                     si = i;
//                     sj = j;
//                 }
//                 if (classroom[i][j] == 'L')
//                 {
//                     litterID[i][j] = litterNum;
//                     ++litterNum;
//                 }
//             }
//         }

//         if (litterNum == 0)
//             return 0;

//         int fullMask = (1 << litterNum) - 1;

//         queue<State> q;
//         A[si][sj][0][maxEnergy] = 0;
//         q.push({si, sj, 0, maxEnergy});
//         while (!q.empty())
//         {
//             State currState = q.front();
//             q.pop();

//             if (currState.energy == 0)
//                 continue;

//             for (int d = 0; d < 4; ++d)
//             {
//                 int ni = currState.i + dir[d][1];
//                 int nj = currState.j + dir[d][0];

//                 if (isValid(ni, nj) && classroom[ni][nj] != 'X')
//                 {
//                     int nextEnergy = (classroom[ni][nj] == 'R') ? maxEnergy : (currState.energy - 1);
//                     int nextMask = currState.mask;
//                     if (litterID[ni][nj] != -1)
//                         nextMask |= (1 << litterID[ni][nj]);
                    
//                     if (A[ni][nj][nextMask][nextEnergy] > A[currState.i][currState.j][currState.mask][currState.energy] + 1)
//                     {
//                         A[ni][nj][nextMask][nextEnergy] = A[currState.i][currState.j][currState.mask][currState.energy] + 1;
//                         if (nextMask == fullMask)
//                             return A[ni][nj][nextMask][nextEnergy]; // 答案
//                         q.push({ni, nj, nextMask, nextEnergy});
//                     }
//                 }
//             }
//         }

//         return -1;
//     }
// };


struct State
{
    int i, j;
    int mask;
    int steps;
};

class Solution 
{
public:
    // bestEnergy[i][j][mask] = 最大energe, mask是收集哪些垃圾的狀壓
    int bestEnergy[25][25][(1 << 10) + 5];
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int m, n;

    int litterID[25][25];

    inline bool isValid(int i, int j)
    {
        return (i >= 0) && (i < m) && (j >= 0) && (j < n);
    }

    /*
        改bestEnergy是因為如果先前如果已經到了這一格，且有的能量更多，此時
        我再走到這一格，但我能量更少，不可能可以走出更好的結果

        這樣狀態可以少一個
    */
    int minMoves(vector<string>& classroom, int maxEnergy) 
    {
        memset(bestEnergy, -1, sizeof(bestEnergy));
        memset(litterID, -1, sizeof(litterID));

        int si, sj;
        int litterNum = 0;

        m = classroom.size();
        n = classroom[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (classroom[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (classroom[i][j] == 'L')
                {
                    litterID[i][j] = litterNum;
                    ++litterNum;
                }
            }
        }

        if (litterNum == 0)
            return 0;

        int fullMask = (1 << litterNum) - 1;

        queue<State> q;
        bestEnergy[si][sj][0] = maxEnergy;
        q.push({si, sj, 0, 0});
        while (!q.empty())
        {
            State currState = q.front();
            q.pop();

            int currEnergy = bestEnergy[currState.i][currState.j][currState.mask];

            if (currEnergy == 0)
                continue;

            for (int d = 0; d < 4; ++d)
            {
                int ni = currState.i + dir[d][1];
                int nj = currState.j + dir[d][0];

                if (isValid(ni, nj) && classroom[ni][nj] != 'X')
                {
                    int nextEnergy = (classroom[ni][nj] == 'R') ? maxEnergy : (currEnergy - 1);
                    int nextMask = currState.mask;
                    if (litterID[ni][nj] != -1)
                        nextMask |= (1 << litterID[ni][nj]);
                    
                    if (bestEnergy[ni][nj][nextMask] < nextEnergy)
                    {
                        bestEnergy[ni][nj][nextMask] = nextEnergy;
                        if (nextMask == fullMask)
                            return currState.steps + 1;
                        q.push({ni, nj, nextMask, currState.steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};