#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool isP[2005][2005];
    // dp[i] -> 前i個字元中，有多少個符合條件的回文
    // 重要觀察: 只需要管長度為k、k + 1的回文
    // 因為如果有個回文的長度 > k + 1
    // 那個回文中一定還包含另一個長度為k或k + 1的小回文
    // 這題只要求數量最多，所以選剛剛好長度的回文就行了
    // 轉移式看下方
    int dp[2005];

    int maxPalindromes(string s, int k) 
    {
        int n = s.size();
        for (int L = 1; L <= n; ++L)
        {
            for (int i = 0; i + L - 1 < n; ++i)
            {
                int j = i + L - 1;
                if (L == 1)
                    isP[i][j] = true;
                else if (L == 2)
                    isP[i][j] = (s[i] == s[j]);
                else if (s[i] == s[j])
                    isP[i][j] = isP[i + 1][j - 1];
                else
                    isP[i][j] = false;
            }
        }

        dp[0] = 0; // 沒有字元
        // 1-based
        for (int i = 1; i <= n; ++i)
        {
            // 不選目前的字元當作回文結尾
            dp[i] = dp[i - 1];

            if (i >= k && isP[i - k][i - 1])
                dp[i] = max(dp[i], dp[i - k] + 1);
            if (i >= k + 1 && isP[i - k - 1][i - 1])
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
        }

        return dp[n];
    }
};