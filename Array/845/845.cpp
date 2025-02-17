#include <bits/stdc++.h>
using namespace std;

#define maxn 10005

class Solution 
{
public:
    /*
        很簡單的題目
        要注意所謂的mountain要有兩邊(沒注意WA一次)
        然後就用left[]維護i的左邊有left[i]個數字比自己小
        right[]維護i的右邊有right[i]個數字比自己小
        之後枚舉一次中間點維護最大答案即可
    */
    int longestMountain(vector<int>& arr) 
    {
        int n = arr.size();

        int left[maxn];
        int right[maxn];
        
        left[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            if (arr[i - 1] < arr[i])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 0;
        }

        right[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            if (arr[i + 1] < arr[i])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 0;
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (left[i] != 0 && right[i] != 0)
                res = max(res, left[i] + right[i] + 1);
        }
        if (res < 3)
            return 0;
        return res;
    }
};