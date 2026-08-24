#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        有趣的規則: 
        每人從左邊拿走x > 1個石頭，然後在最左邊放上那些石頭的sum的石頭

        假設原本石頭 [a, b, c, d, e]
        前綴和: [P0, P1, P2, P3, P4]
        Alice拿走x = 3
        拿到分數 a + b + c = P2
        陣列變成[P2, d, e]
        
        所以可以發現每次操作其實都是拿走該位置的前綴和

        定義面對上一個玩家合併到第i顆石頭的局面時，
        當前玩家從j > i決策能夠獲得的最大分數差異dp[i]

        所以dp轉移式就很清楚
        dp[i] = max{ P_j - dp[j] } where i < j

        但是這樣要O(n^2)
        觀察到
        dp[i] = max{ P_{i + 1} - dp[i + 1], max_{i + 1 < j}{ P_j - dp[j] } }
        後面的max_{i + 1 < j}{ P_j - dp[j] }其實就是dp[i + 1]

        所以dp[i] = max{ P_{i + 1} - dp[i + 1], dp[i + 1] }

        這樣就能O(n)了
    */
    int stoneGameVIII(vector<int>& stones) 
    {
        int n = stones.size();
        vector<int> prefix(n + 5);
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + stones[i];
        
        vector<int> dp(n + 5, 0);
        // 上一人停在n - 2時，唯一能選的是最後一顆石頭以及P_{n - 2}
        // 上一人停在n - 2是唯一還需要進行最後一顆石頭的情況
        // 其他情況會直接是玩家直接拿完，剩一顆石頭，遊戲就結束了
        dp[n - 2] = prefix[n - 1];
        for (int i = n - 3; i >= 0; --i)
            dp[i] = max(prefix[i + 1] - dp[i + 1], dp[i + 1]);
        
        return dp[0];
    }
};