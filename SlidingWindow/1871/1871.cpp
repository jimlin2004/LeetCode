#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

class Solution 
{
public:
    // 很直覺的能想到O(n ^ 2)的方式
    // 也就是枚舉i的同時維護那些區間我能跳
    // 但會超時
    // 要改用cnt去數一個區間有多少位置可以跳到i
    // 才能O(n)
    bool canReach(string s, int minJump, int maxJump) 
    {
        int n = s.size();

        bool reachable[maxn];
        memset(reachable, 0, sizeof(reachable));
        reachable[0] = true;

        int cnt = 0; // 數著有多少的 i - maxJump ~ i - minJump 的點可以站，那些點可以跳到i

        // 枚舉所有位置
        for (int i = 1; i < n; ++i)
        {
            // 更新cnt
            if (i >= minJump)
                cnt += reachable[i - minJump];
            if (i >= maxJump + 1)
                cnt -= reachable[i - maxJump - 1]; // maxJump - 1已經脫離 i - maxJump ~ i - minJump的範圍
            
            // 前面有位置可以跳過來
            if (cnt > 0 && s[i] == '0')
                reachable[i] = true;
        }

        return reachable[n - 1];
    }
};