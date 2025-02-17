#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    /*
        簡單題
        將groupSizes[i]的通通分類好
        然後就能隨便分
        每一組可分groupSizes[i]個人(隨便分)
    */
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        int n = groupSizes.size();
        vector<vector<int>> cntMp(n + 5, vector<int>());
        for (int i = 0; i < n; ++i)
        {
            cntMp[groupSizes[i]].emplace_back(i);
        }

        vector<vector<int>> res;
        for (int i = 1; i <= n; ++i)
        {
            if (!cntMp[i].empty())
            {
                for (int j = 0; j < cntMp[i].size(); j += i)
                {
                    vector<int> group;
                    for (int k = 0; k < i; ++k)
                    {
                        group.emplace_back(cntMp[i][j + k]);
                    }
                    res.emplace_back(group);
                }
            }
        }
        return res;
    }
};