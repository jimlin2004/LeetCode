#include <bits/stdc++.h>
using namespace std;

struct State
{
    long long maxWeights = 0;
    vector<int> indices;
};

// 為了排序後保留原本的index
struct Interval
{
    int l, r, weight, id;
};

class Solution 
{
public:
    /*
        給定一堆區間，每個區間有weight
        求選最多4個不重疊區間能夠有最大的weight總和
        另外，要的是選的indices，然後要indices字典序最小

        首先先將所有區間以右端點排序，保證單調性
        dp其實蠻明顯，第一個狀態會是選或不選
        第二個狀態會是選了幾個

        然後因為這題要的是indices，所以在dp狀態中還要記錄indices怎麼選的
    */

    State dp[50005][5]; //dp[i][j] -> 考慮到第i個區間，選了j個

    vector<int> maximumWeight(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        vector<Interval> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(A.begin(), A.end(), [](const Interval& a, const Interval& b){
            return a.r < b.r;
        });

        auto cmp_state = [](const State& a, const State& b) {
            if (a.maxWeights != b.maxWeights)
                return a.maxWeights < b.maxWeights;
            return a.indices > b.indices;
        };

        // clear
        for (int i = 0; i < n; ++i) 
        {
            for (int k = 0; k <= 4; ++k) 
            {
                dp[i][k] = State{0, {}};
            }
        }

        dp[0][1] = {A[0].weight, {A[0].id}};
        for (int i = 1; i < n; ++i)
        {
            auto& currInterval = A[i];

            // 找到最後一個在currInterval以前的區間
            // 因為右端點已排序，所以可以二分搜優化
            auto it = lower_bound(A.begin(), A.begin() + i, currInterval.l, [](const Interval& interval, int tl){
                return interval.r < tl;
            });
            int p = it - A.begin() - 1; // 轉成index

            for (int k = 1; k <= 4; ++k)
            {
                // i不選
                dp[i][k] = dp[i - 1][k];

                // i選
                if (k == 1)
                {
                    State state = {currInterval.weight, {currInterval.id}};
                    dp[i][k] = max(dp[i][k], state, cmp_state);
                }
                // 只有前一個區間的狀態合法時可以算
                if (p != -1 && !dp[p][k - 1].indices.empty())
                {
                    State state;
                    state.maxWeights = dp[p][k - 1].maxWeights + currInterval.weight;
                    state.indices = dp[p][k - 1].indices;
                    // 選i，但是要保持state.indices的由小到大，所以用insert的
                    state.indices.insert(lower_bound(state.indices.begin(), state.indices.end(), currInterval.id), currInterval.id);
                
                    dp[i][k] = max(dp[i][k], state, cmp_state);
                }
            }
        }

        State res;
        for (int k = 1; k <= 4; ++k)
        {
            if (!dp[n - 1][k].indices.empty())
            {
                res = max(res, dp[n - 1][k], cmp_state);
            }
        }

        return res.indices;
    }
};