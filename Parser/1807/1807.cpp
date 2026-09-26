#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 簡單用個狀態處理parser就行
    string evaluate(string s, vector<vector<string>>& knowledge) 
    {
        unordered_map<string, string> mp;
        for (const auto& p: knowledge)
            mp[p[0]] = p[1];
        
        string res("");
        string key("");

        bool is_in_bracket = false;

        for (char c: s)
        {
            if (c == '(')
                is_in_bracket = true;
            else if (c == ')')
            {
                auto it = mp.find(key);
                if (it != mp.end())
                    res += it->second;
                else
                    res += "?";

                key = "";
                is_in_bracket = false;
            }
            else
            {
                if (is_in_bracket)
                    key += c;
                else
                    res += c;
            }
        }

        return res;
    }
};