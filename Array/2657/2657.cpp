#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 水題，用陣列就好，也可以用bit去壓
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        bool A_has[55];
        bool B_has[55];
        memset(A_has, 0, sizeof(A_has));
        memset(B_has, 0, sizeof(B_has));
        vector<int> C;
        int n = A.size();
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            A_has[A[i]] = true;
            B_has[B[i]] = true;
            if (A_has[B[i]])
                ++cnt;
            if (B_has[A[i]])
                ++cnt;
            if (A[i] == B[i]) // 如果一樣不要重複算到
                --cnt;
            if (C.empty())
                C.emplace_back(cnt);
            else
                C.emplace_back(C.back() + cnt);
        }
        return C;
    }
};