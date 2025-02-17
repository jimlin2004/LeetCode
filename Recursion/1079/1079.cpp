#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int dfs(int cnt[])
    {
        int total = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] == 0)
                continue;
            ++total;
            --cnt[i];
            total += dfs(cnt);
            ++cnt[i];
        }
        return total;
    }

    /*
        理論上可以用數學算
        似乎也有DP解(看其他人)
        但都比較麻煩

        這題數值範圍在n <= 7
        所以可以直接遞迴暴搜

        如何暴搜有不同做法
        首先自然是count字元的數量
        最簡單就是用遞迴搜不斷地建字串然後一個個加起來
        或是建完字串數重複的用多項式定理直接算

        但其實也能簡單的用
        第一格放什麼字、第二格放什麼字
        只要維護一個cnt[]
        在每一格遇到cnt[i]不是零的就可以放
        然後遞迴下一格
        同時每一格都要+1
        因為長度可以不用全用完
        以這樣的方式還可以避免需要除掉重複排列的
    */
    int numTilePossibilities(string tiles) 
    {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));

        for (char c: tiles)
            ++cnt[c - 'A'];
        
        return dfs(cnt);
    }
};