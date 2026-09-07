#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        算出所有s中不相同的subsequence個數

        原本我以為是用2^n - 1 - 重複
        但重複很難算
        以下有參考題解:
        觀察到每一個非空的subsequence結尾一定是a ~ z
        定義:
        endWith[c]: 以字元c結尾的相異子序列個數
        total: 所有相異的子序列個數

        當遇到一個新的字元 x 時
        1. 可以拿目前所有相異的子序列total後面接上x，形成新的子序列，共total個
        2. x可以是自己一個新的子序列，共1個

        所以每次更新答案時:
        1. new_endWith[x] = total + 1
        2. diff = new_endWith[x] - endWith[x]
        3. total = total + diff
        4. endWith[x] = new_endWith[x]

        為什麼x不會重複，以"aaa"為例:
            第一次遇到'a'，
            endWith['a'] = {"a"}
            total = 1
            第二次遇到'a'，
            endWith['a'] = {"aa", "a"}
            第三次遇到'a'，
            endWith['a'] = {"aaa", "aa", "a"}
        所以用這種計算方式可以天然去重
    */
    int distinctSubseqII(string s) 
    {
        constexpr int MOD = 1000000007;

        int n = s.size();
        vector<int> endWith(26 + 5, 0);
        
        int total = 0;
        for (char ch: s)
        {
            int c = ch - 'a';

            int newEndWithC = (total + 1) % MOD;
            total = ( total + (newEndWithC - endWith[c] + MOD) % MOD ) % MOD;
            endWith[c] = newEndWithC;
        }

        return total;
    }
};