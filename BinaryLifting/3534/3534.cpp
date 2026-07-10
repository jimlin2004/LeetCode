#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        這題是難題
        以下做法是有查詢ai的

        首先N = 10^5
        說明不能建構真的圖，會超時
        題目說有邊的定義是 (| nums[i] - nums[j] | <= maxDiff)
        也就是說如果nums[u] = val，那他能去到的nodes只能是[val - maxDiff, val + maxDiff]的

        由於只看數值，所以先將node以數值排序
        此時就是一個由小到大的數線

        現在假設要從數線上A -> B
        因為要最短跳躍次數，所以要貪心的每次往右跳到最遠
        (也就是現在站在X，下一個要跳到X + maxDiff的最大數值)

        所以這一題變成在數線上貪心問題

        但是每次都做貪婪還是會TLE，
        正確作法是建倍增表
        right_jump[i][step] = 從第i個數線的數值開始，往右跳2^step次，最遠能到哪裡
        如此每次查詢都只要O(log N)的時間

        細節看下方
    */

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
    {
        // 轉成數線
        vector<int> numberLine(nums);
        sort(numberLine.begin(), numberLine.end());
        // 去重
        int m = unique(numberLine.begin(), numberLine.end()) - numberLine.begin();

        // 為了將nums轉到numberLine，用Hash table離散化
        unordered_map<int, int> numsToNumberLine;
        for (int i = 0; i < m; ++i)
        {
            numsToNumberLine[numberLine[i]] = i;
        }

        int maxStep = 20; // 2^20足夠10^5
        // 倍增表
        vector<vector<int>> right_jump(m + 5, vector<int>(maxStep));

        // 處理每個numberLine[i] + maxDiff的最大值
        for (int i = 0; i < m; ++i)
        {
            // 找到不大於numberLine[i] + maxDiff的最大值
            // 用二分搜加速處理
            auto it = upper_bound(numberLine.begin(), numberLine.begin() + m, numberLine[i] + maxDiff);
            right_jump[i][0] = prev(it) - numberLine.begin(); // 因為是不大於，所以要prev
        }
        // 處理倍增表
        for (int step = 1; step < maxStep; ++step)
        {
            for (int i = 0; i < m; ++i)
            {
                // i的第2^step的祖先是i的第2^(step - 1)的祖先的第2^(step - 1)的祖先
                right_jump[i][step] = right_jump[right_jump[i][step - 1]][step - 1];
            }
        }

        vector<int> res;
        for (const auto& query: queries)
        {
            int u = query[0];
            int v = query[1];

            // 同一個點
            if (u == v)
            {
                res.emplace_back(0);
                continue;
            }
            // 同一個數值但不同node，都只要一次跳躍
            if (nums[u] == nums[v])
            {
                res.emplace_back(1);
                continue;
            }

            int from = numsToNumberLine[nums[u]];
            int to = numsToNumberLine[nums[v]];

            // 強制讓from在to的左邊
            // 因為是無向圖，所以距離是對稱的
            if (from > to)
                swap(from, to);
            
            // 如果往右跳2^step步都到不了，那就一定不相連的
            if (right_jump[from][maxStep - 1] < to)
            {
                res.emplace_back(-1);
            }
            else
            {
                // 倍增法往右跳
                int jumps = 0;
                int curr = from;
                for (int step = maxStep - 1; step >= 0; --step)
                {
                    // 還沒到，就繼續跳
                    if (right_jump[curr][step] < to)
                    {
                        curr = right_jump[curr][step];
                        jumps += (1 << step); // 記得是一次跳了2^step次
                    }
                }
                // 最後會停在to的前面，此時只要再跳一次即可
                res.emplace_back(jumps + 1);
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {2, 5, 2};
    vector<vector<int>> queries = {{0, 1}, {2, 2}};
    Solution sol;
    sol.pathExistenceQueries(3, nums, 20, queries);

    return 0;
}