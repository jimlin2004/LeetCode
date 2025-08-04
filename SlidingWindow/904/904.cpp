#include <bits/stdc++.h>
using namespace std;


#define maxn 100005

class Solution 
{
public:

    int cnt[maxn];

    /*
        簡單滑動窗戶
        只要保持窗戶只有2種type
        超過2種時l開始往右縮
        維護最好答案即可
    */
    int totalFruit(vector<int>& fruits) 
    {
        memset(cnt, 0, sizeof(cnt));

        int n = fruits.size();

        int type = 0; // window裡有幾種

        int res = 0;
        int window = 0;

        int l = 0, r = 0;
        while (r < n)
        {
            if (cnt[fruits[r]] == 0)
                ++type;
            ++cnt[fruits[r]];
            ++window;

            while (type > 2)
            {
                if (cnt[fruits[l]] == 1)
                    --type;

                --cnt[fruits[l]];
                --window;
                ++l;
            }

            res = max(res, window);

            ++r;
        }

        return res;
    }
};