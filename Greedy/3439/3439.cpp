#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime)
    {
        int n = startTime.size();

        // 會議時間的prefix
        vector<int> prefix(n + 5, 0);
        for (int i = 1; i <= n; ++i)
        {
            prefix[i] = prefix[i - 1] + (endTime[i - 1] - startTime[i - 1]);
        }

        // greedy
        // 由於k個會議會有k + 1個間隔
        // 將所有工作排在一起能讓間隔加總起來
        // 所以就k個工作排在一起看哪k個排一起放到最前面有最大的休息時間

        int res = 0;
        for (int i = k; i <= n; ++i)
        {
            int left = (i == k) ? 0 : endTime[i - k - 1]; // 前一個沒有調的會議結束時間
            int right = (i == n) ? eventTime : startTime[i]; // 沒有調的第一個會議開始時間

            // 全部時間 - 這k個會議的時間 = 能留下來的空閒時間
            res = max(res, right - left - (prefix[i] - prefix[i - k]));
        }

        return res;
    }
};


int main()
{
    Solution S;
    vector<int> startTime = {0,2,9};
    vector<int> endTime = {1,4,10};
    S.maxFreeTime(10, 1, startTime, endTime);
    return 0;
}