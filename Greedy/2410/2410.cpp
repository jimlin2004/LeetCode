#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // players與trainers由大到小排之後
    // 永遠當前最大的trainers想辦法去配對players即可得到答案
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        sort(players.rbegin(), players.rend());
        sort(trainers.rbegin(), trainers.rend());

        int playerPtr = 0;
        int trainerPtr = 0;

        int n = players.size();
        int m = trainers.size();

        int res = 0;

        while (playerPtr < n && trainerPtr < m)
        {
            if (players[playerPtr] <= trainers[trainerPtr])
            {
                ++res;
                ++playerPtr;
                ++trainerPtr;
            }
            else // players[playerPtr] > trainers[trainerPtr]
            {
                ++playerPtr;
            }
        }

        return res;
    }
};