#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int arr[1700] = {1};

        // 現在還沒乘過2、3、5的是哪個數字
        int ptr2 = 0;
        int ptr3 = 0;
        int ptr5 = 0;

        for (int i = 1; i < n; ++i)
        {
            int next2 = arr[ptr2] * 2;
            int next3 = arr[ptr3] * 3;
            int next5 = arr[ptr5] * 5;

            arr[i] = min({next2, next3, next5});

            // 這裡要用if才能去除重複，比如6 = 2 x 3 = 3 x 2
            if (next2 == arr[i]) ++ptr2;
            if (next3 == arr[i]) ++ptr3;
            if (next5 == arr[i]) ++ptr5;
        }

        return arr[n - 1];
    }
};