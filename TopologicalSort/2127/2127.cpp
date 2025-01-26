#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        考圖上多種技巧的題目(有參考題解)
        合法的排列分為幾種情況
        1. 圖上的環，對於那些大小 > 2的環，他們可以決定唯一的會議參與人(只有在該環裡的人才能參加會議)
        2. 圖上的鍊，對於那些單鍊可以決定出一個會議
        3. 
            大小為2的簡單環很重要，因為他們互相喜歡，所以他們可以當作連接兩條鍊的接點
            由此特性可知，只要有大小為2的環出現，我們可以利用全部的大小為2的環連接多個鍊成為一個大會議
            所以看到有大小為2的環，要將他們的深度(以他們為結束的兩條鍊長度)全部加起來
        最後比較用環還是多個鍊串起來可以得到最大的會議
        (參考 推導1.png)

        另外這題是簡單圖，一個node只會有一個出去的edge，因此不會有大小環的問題(推導2.png)
        也由於簡單圖，找環與環的大小可以用dfs直到edge指回找過的node就是找到環了
    */
    int maximumInvitations(vector<int>& favorite) 
    {
        int n = favorite.size();
        // favorite可以當作一種directed graph
        // favorite的indegree
        vector<int> indegree(n + 5, 0);
        for (int u = 0; u < n; ++u)
        {
            ++indegree[favorite[u]];
        }
        
        // 將不是環的鍊計算最大深度(用拓樸找)
        // 所謂的深度其實可以想成從u出發的invert graph到底的最大長度
        vector<int> depth(n + 5, 1);
        queue<int> q;
        for (int u = 0; u < n; ++u)
        {
            if (indegree[u] == 0)
                q.push(u);
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            int v = favorite[u];
            depth[v] = max(depth[v], depth[u] + 1);
            --indegree[v];
            if (indegree[v] == 0)
                q.push(v);
        }

        int maxCycleSize = 0, twoCycleComponentSize = 0;
        // 到這裡若還有indegree[u] != 0 -> u在一個環裡
        for (int i = 0; i < n; ++i)
        {
            // indegree[u] = 0 -> u已經處理完了
            if (indegree[i] == 0)
                continue;
            // 從i出發，找到那個環的大小
            int cycleSize = 0;
            int u = i;
            while (indegree[u] != 0)
            {
                indegree[u] = 0; // 標記為找過了
                ++cycleSize;
                u = favorite[u];
            }
            if (cycleSize == 2)
            {
                // 該環是只有兩個node的簡單環
                twoCycleComponentSize += depth[i] + depth[favorite[i]];
            }
            else
                maxCycleSize = max(maxCycleSize, cycleSize);
        }
        return max(maxCycleSize, twoCycleComponentSize);
    }
};