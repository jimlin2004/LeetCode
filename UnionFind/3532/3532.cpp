#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:

    int ccCnt = 0;
    int connectedComponents[100005];

    /*
        因為這一題的edge是abs(相差) <= maxDiff
        且nums已經由小到大排序過
        因此如果建成多個connected component會發現
        每個component都是一條線段

        所以先預處理好connected component
        之後直接查詢即可

        其實就是比較特殊的併查集
    */
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
    {
        for (int i = 0; i < n;)
        {
            connectedComponents[i] = ccCnt++;
            int j = i + 1;
            while (j < n && abs(nums[j] - nums[j - 1]) <= maxDiff)
            {
                // 同一個connected component
                connectedComponents[j] = connectedComponents[i];
                ++j;
            }
            i = j;
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i)
        {
            const auto& query = queries[i];
            ans[i] = (connectedComponents[query[0]] == connectedComponents[query[1]]);
        }

        return ans;
    }
};