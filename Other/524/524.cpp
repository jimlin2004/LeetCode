#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //檢查a能不能透過刪除得到b
    bool check(string& a, string& b)
    {
        //a理論上要比b長，否則不可能可以透過刪除得到b
        if (a.size() < b.size())
            return false;
        int l = 0, r = 0;
        while (l < a.size() && r < b.size())
        {
            if (a[l] == b[r])
                ++r;
            ++l;
        }
        return r == b.size();
    }

    //我只會暴搜
    string findLongestWord(string s, vector<string>& dictionary)
    {
        string res = "";
        for (string& b: dictionary)
        {
            if (check(s, b))
            {
                if (res.size() < b.size())
                    res = b;
                else if (res.size() == b.size())
                {
                    if (res > b)
                        res = b;
                }
            }
        }
        return res;
    }
};