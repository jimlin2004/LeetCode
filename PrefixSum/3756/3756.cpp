#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    const int MOD = 1000000007;

    /*
        prefix[i] = prefix[i - 1] * 10 + arr[i]
        ex: arr[5] = {1, 2, 3, 4, 5}
        prefix[0] = 1
        prefix[1] = 12
        prefix[2] = 123
        prefix[3] = 1234
        prefix[4] = 12345

        要取[2, 3] -> 1234 - 12 * 100 -> prefix[3] - prefix[1] * 10^2
        所以通式: prefix[r] - prefix[l - 1] * 10^(R - L + 1)
        然後記得要mod

        概念其實跟rolling hash公式挺像的

        然後因為要跳過0，所以要稍微改一點
    */
    long long prefixMultSum[100005];
    int nonZeroCnt[100005]; // 到i為止有多少個數字不是0，用來算pow10的冪次
    long long pow10[100005];
    long long prefixSum[100005];

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) 
    {
        int n = s.size();
        pow10[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            pow10[i] = pow10[i - 1] * 10 % MOD;
        }

        if (s[0] != '0')
        {
            prefixMultSum[0] = s[0] - '0';
            prefixSum[0] = s[0] - '0';
            nonZeroCnt[0] = 1;
        }
        else
        {
            prefixMultSum[0] = 0;
            prefixSum[0] = 0;
            nonZeroCnt[0] = 0;
        }
        for (int i = 1; i < n; ++i)
        {
            char c = s[i];
            if (c == '0')
            {
                // 延續之前的
                prefixMultSum[i] = prefixMultSum[i - 1];
                prefixSum[i] = prefixSum[i - 1];
                nonZeroCnt[i] = nonZeroCnt[i - 1];
            }
            else
            {
                prefixMultSum[i] = ((prefixMultSum[i - 1] * 10 + s[i] - '0') % MOD) % MOD;
                prefixSum[i] = ( prefixSum[i - 1] + (s[i] - '0') ) % MOD;
                nonZeroCnt[i] = nonZeroCnt[i - 1] + 1;
            }
        }

        vector<int> resVec;
        for (auto& query: queries)
        {
            int l = query[0];
            int r = query[1];

            int nonZeroLen = nonZeroCnt[r] - ((l == 0) ? 0 : nonZeroCnt[l - 1]);
            if (nonZeroLen == 0)
            {
                // 全都是0
                resVec.emplace_back(0);
            }
            else if (l == 0)
            {
                int res = prefixMultSum[r];
                res = ( res * prefixSum[r] ) % MOD;
                resVec.emplace_back(res);
            }
            else
            {
                int res = ( prefixMultSum[r] - (prefixMultSum[l - 1] * pow10[nonZeroLen]) % MOD + MOD ) % MOD;
                res = ( res * (prefixSum[r] - prefixSum[l - 1] + MOD) % MOD ) % MOD;
                resVec.emplace_back(res);
            }
        }

        return resVec;
    }
};

int main()
{
    string s = "10203004";
    vector<vector<int>> queries = {
        {0,7},{1,3},{4,6}
    };
    Solution sol;
    sol.sumAndMultiply(s, queries);

    return 0;
}