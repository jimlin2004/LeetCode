#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題
    int findLucky(vector<int>& arr) 
    {
        int freqs[505];
        memset(freqs, 0 ,sizeof(freqs));
        for (int v: arr)
            ++freqs[v];
        
        int res = -1;
        
        for (int i = 504; i >= 1; --i)
        {
            if (freqs[i] == i)
            {
                res = i;
                break;
            }
        }

        return res;
    }
};