#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        int ln = s.size();
        int result = 0;
        for (int i = 0; i < ln; i++)
        {
            if (i != ln - 1)
            {
                if (this->R2I[s[i]] < this->R2I[s[i + 1]])
                {
                    result += (this->R2I[s[i + 1]] - this->R2I[s[i]]);
                    i ++;
                }
                else
                    result += this->R2I[s[i]];
            }
            else
                result += this->R2I[s[i]];
        }
        return result;
    }
private:
    map<char, int> R2I = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};