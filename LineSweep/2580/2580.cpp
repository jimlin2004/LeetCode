#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution 
{
public:
    int countWays(vector<vector<int>>& ranges) 
    {
        // 區間排序
        sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });

        // 數有多少個獨立區間
        int cnt = 0;
        int pos = -1;
        for (auto& range: ranges)
        {
            if (pos < range[0])
            {
                ++cnt;
                pos = range[1];
            }
            else
                pos = max(pos, range[1]);
        }

        // 答案為2 ^ n個方法，因為每個獨立區間可以當作切點，所以每個切點可選可不選
        int res = 1;
        for (int i = 0; i < cnt; ++i)
        {
            res = (res * 2) % MOD;
        }
        return res;
    }
};


int main()
{
    vector<vector<int>> ranges = {{34,56},{28,29},{12,16},{11,48},{28,54},{22,55},{28,41},{41,44}};
    Solution S;
    S.countWays(ranges);
}