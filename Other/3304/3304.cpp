#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    inline char asciiShift(char c, int shift)
    {
        static int start = 'a';
        int normailzedShift = (shift % 26 + 26) % 26; //處理負數
        return (char)((c - start + normailzedShift) % 26 + start); 
    }

    string create(string s)
    {
        for (int i = 0; i < s.size(); ++i)
            s[i] = asciiShift(s[i], 1);
        return s;
    }

    char kthCharacter(int k)
    {
        string str = "a";
        while (str.size() < k)
        {
            str += create(str);
        }
        return str[k -  1];
    }
};


int main()
{
    Solution S;
    S.kthCharacter(5);
    return 0;
}