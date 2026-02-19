#include <bits/stdc++.h>
using namespace std;

// 數一數答案就過了

class Solution 
{
private:
    int cnt[300];

    int Left[100005]; // 左邊數過來
    int Right[100005]; // 右邊數過來
public:
    int numSplits(string s)
    {
        int n = s.size();

        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < n; ++i)
        {
            if (cnt[s[i]] == 0)
                ++Left[i];
            ++cnt[s[i]];
            if (i > 0)
                Left[i] += Left[i - 1];
        }

        memset(cnt, 0, sizeof(cnt));

        for (int i = n - 1; i >= 0; --i)
        {
            if (cnt[s[i]] == 0)
                ++Right[i];
            ++cnt[s[i]];
            if (i < n - 1)
                Right[i] += Right[i + 1];
        }

        // 數答案
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            if (Left[i - 1] == Right[i])
                ++res;
        }

        return res;
    }
};