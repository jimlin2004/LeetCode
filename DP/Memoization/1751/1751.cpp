#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // dp[i][k] -> 到1 ~ k個event中參加k個event時最大獲利
    vector<vector<int>> dp;
    vector<vector<int>> events;
    int k;

    // 二分搜第一個 startDay > currDay的index
    int bs(int currDay)
    {
        int l = -1; // <= currDay的上界
        int r = this->events.size(); // > currDay的下界
        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (this->events[mid][0] <= currDay)
                l = mid;
            else
                r = mid;
        }

        return r;
    }

    // O(n * k * logn)
    // 第index個event，已經參加cnt個event
    int dfs(int index, int cnt)
    {
        if (cnt == k)
            return 0;

        if (index == this->events.size())
            return 0;

        if (dp[index][cnt] != -1)
            return dp[index][cnt];
        
        /*
            dp[index][cnt]時可以選events[index]或者不選
            選的話就是遞迴到下一個可以參加的event開始討論或是直接跳過當前event到下一個events
            看是dp[nextIndex][cnt + 1] + events[index][2] 還是dp[index + 1][cnt]比較好
        */
        int nextIndex = bs(this->events[index][1]);
        dp[index][cnt] = max(dfs(nextIndex, cnt + 1) + this->events[index][2], dfs(index + 1, cnt));

        return dp[index][cnt];
    }

    int maxValue(vector<vector<int>>& events, int k)
    {
        this->events = move(events);
        this->k = k;

        int n = this->events.size();
        dp.assign(n + 5, vector<int>(k + 5, -1));

        // 由起點排序
        sort(this->events.begin(), this->events.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        return dfs(0, 0);
    }
};


int main()
{
    Solution S;
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    S.maxValue(events, 2);

    return 0;
}