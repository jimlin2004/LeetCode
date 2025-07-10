#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime)
    {
        int n = startTime.size();

        vector<int> gaps(n + 5, 0);
        // 計算所有會議的間隔，包含0 ~ 第一個會議以及最後一個會議 ~ eventTime
        gaps[0] = startTime[0] - 0;
        for (int i = 1; i < n; ++i)
            gaps[i] = startTime[i] - endTime[i - 1];
        gaps[n] = eventTime - endTime[n - 1];

        // 左邊/右邊(包含自己)的最大gap是多少
        vector<int> leftMaxGap(n + 5, 0);
        vector<int> rightMaxGap(n + 5, 0);

        leftMaxGap[0] = gaps[0];
        for (int i = 1; i <= n; ++i)
            leftMaxGap[i] = max(leftMaxGap[i - 1], gaps[i]);
        
        rightMaxGap[n] = gaps[n];
        for (int i = n - 1; i >= 0; --i)
            rightMaxGap[i] = max(rightMaxGap[i + 1], gaps[i]);
        
        int res = 0;
        // greedy
        // 兩個選擇
        // 如果除了當前會議i的相鄰兩個gap的其他gaps能裝得下會議i，就把會議i搬過去 -> 答案是兩個相鄰gap相加 + 會議原本占掉的長度
        // 如果不行，就只能會議i移到最前面讓兩個gaps能夠結合 -> 答案是兩個gap相加
        for (int i = 0; i < n; ++i)
        {
            // 注意LG與RG不能是相鄰的兩個gap其中一個
            int LG = (i - 1 >= 0) ? leftMaxGap[i - 1] : 0;
            int RG = (i + 2 <= n) ? rightMaxGap[i + 2] : 0;

            if (endTime[i] - startTime[i] <= max(LG, RG)) // 會議i能搬到其他gap去
            {
                res = max(res, gaps[i] + gaps[i + 1] + (endTime[i] - startTime[i]));
            }
            else // 只能位移會議i
            {
                res = max(res, gaps[i] + gaps[i + 1]);
            }
        }

        return res;
    }
};