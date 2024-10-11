#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        int priority[30];
        for (int i = 0; i < order.size(); ++i)
        {
            //取負是為了讓數字小的priority比較大
            priority[order[i] - 'a'] = i;
        }

        //以priority[]排序
        sort(s.begin(), s.end(), [=](const char a, const char b) {
            return priority[a - 'a'] < priority[b - 'a'];
        });

        return s;
    }
};