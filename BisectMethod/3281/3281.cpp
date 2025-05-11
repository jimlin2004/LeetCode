#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    // 算簡單的bisect method，但這題要用long long，回傳時硬用int
    int maxPossibleScore(vector<int>& start, int d) 
    {
        sort(start.begin(), start.end());

        long long L = -1, R = 2000000005;
        while (L + 1 < R)
        {
            long long mid = ((R - L) >> 1) + L;
            if (check(mid, start, d))
                L = mid;
            else
                R = mid;
        }
        return L;
    }

    // 用greedy去檢查
    bool check(long long len, vector<int>& start, int d)
    {
        long long prev = start[0];
        int n = start.size();
        for (int i = 1; i < n; ++i)
        {
            if (prev + len < start[i]) // 上一個數字加上len甚至沒碰到
                prev = start[i];
            else if (prev + len <= start[i] + d) // 在start ~ start + d
                prev = prev + len;
            else // prev + len > start + d
                return false;
        }

        return true;
    }
};