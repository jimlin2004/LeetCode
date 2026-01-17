#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 注意: 這一題的意思是指能用一個語言，教最少的人能夠全部溝通
    // 所以greedy + 暴搜
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
    {
        // 不能溝通的
        unordered_set<int> cannotComm;

        // p1會哪些，方便查找
        bool p1Can[505];
        for (auto& friendship: friendships)
        {
            // 用0-index based
            int p1 = friendship[0] - 1;
            int p2 = friendship[1] - 1;

            memset(p1Can, 0, sizeof(p1Can));
            // p1會哪些
            for (int lang: languages[p1])
                p1Can[lang] = true;

            // 找p1跟p2是否能溝通
            bool ok = false;
            for (int lang: languages[p2])
            {
                if (p1Can[lang])
                {
                    ok = true;
                    break;
                }
            }
            if (!ok)
            {
                cannotComm.insert(p1);
                cannotComm.insert(p2);
            }
        }

        // 暴力搜尋每個語言哪個需要教的人最少
        int cnt[505];
        memset(cnt, 0, sizeof(cnt));
        for (int p: cannotComm)
        {
            for (int lang: languages[p])
                ++cnt[lang];
        }

        /*
            最少要教的人 = 不能溝通的人數 - 最多人會的
        */
        return cannotComm.size() - *max_element(cnt, cnt + 505);
    }
};