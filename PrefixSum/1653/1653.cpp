#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

class Solution 
{
public:
    // 數一數leftB跟rightA然後枚舉最優中間點即可
    int minimumDeletions(string s) 
    {
        int n = s.size();

        int leftB[maxn]; // i的左邊有多少b
        int rightA[maxn]; // i的右邊有多少a

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            leftB[i] = cnt;
            cnt += (s[i] == 'b');
        }

        cnt = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            rightA[i] = cnt;
            cnt += (s[i] == 'a');
        }

        int res = 0x3f3f3f3f;
        // 枚舉中間點
        for (int i = 0; i < n; ++i)
        {
            res = min(res, leftB[i] + rightA[i]);
        }

        return res;
    }
};