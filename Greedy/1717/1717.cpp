#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        貪婪
        先刪高分的再刪低分的會對
        主要是因為這一題裡ab跟ba用的字元是一樣的
        此時若先嘗試低分的可能會破壞獲得高分的機會
        所以用stack然後先刪高分再刪低分的就行了
    */
    int maximumGain(string s, int x, int y) 
    {
        string higherSubstring = (x < y) ? "ba" : "ab";
        string lowerSubstring = (higherSubstring == "ab") ? "ba" : "ab";

        int res = 0;
        
        int cnt;

        tie(s, cnt) = removeSubstring(s, higherSubstring);
        res += cnt * max(x, y);

        tie(s, cnt) = removeSubstring(s, lowerSubstring);
        res += cnt * min(x, y);

        return res;
    }

    pair<string, int> removeSubstring(const string& s, const string& substring)
    {
        vector<char> sk;

        int cnt = 0; // 找到的次數

        for (char ch: s)
        {
            sk.emplace_back(ch);

            // 找到了
            if (sk.size() >= 2 && sk[sk.size() - 2] == substring[0] && sk.back() == substring[1])
            {
                ++cnt;
                sk.pop_back();
                sk.pop_back();
            }
        }

        return {string(sk.begin(), sk.end()), cnt};
    }
};

int main()
{
    Solution S;
    string str = "cdbcbbaaabab";
    S.maximumGain(str, 4, 5);

    return 0;
}