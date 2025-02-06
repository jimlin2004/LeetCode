#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // O(n)找到不一樣的兩個位置
    // 交換看看能不能一樣
    bool areAlmostEqual(string s1, string s2) 
    {
        int n = s1.size();

        int i = 0;
        while (i < n && s1[i] == s2[i])
            ++i;
        if (i == n)
            return true; // 已經排好序了
        int j = i + 1;
        while (j < n && s1[j] == s2[j])
            ++j;
        // 避免j溢位
        swap(s1[i], s1[min(j, n)]);
        return s1 == s2;
    }
};