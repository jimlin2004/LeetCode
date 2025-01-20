#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 用陣列預處理值的位置就好
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int posC[100005], posR[100005];
        int cntC[100005], cntR[100005];
        memset(cntC, 0, sizeof(cntC));
        memset(cntR, 0, sizeof(cntR));
        int m = mat.size(), n = mat[0].size();

        // O(m x n)處理值在mat的位置
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                posR[mat[i][j]] = i;
                posC[mat[i][j]] = j;
            }
        }

        // O(len(arr))找第一個bingo的地方
        int L = arr.size();
        int val;
        for (int i = 0; i < L; ++i)
        {
            val = arr[i];
            ++cntR[posR[val]];
            ++cntC[posC[val]];
            if (cntR[posR[val]] == n || cntC[posC[val]] == m)
                return i;
        }
        return -1;
    }
};