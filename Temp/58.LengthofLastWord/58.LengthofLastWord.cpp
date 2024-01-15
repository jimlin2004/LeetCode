#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        reverse(s.begin(), s.end());
        stringstream ss;
        string result;
        ss << s;
        ss >> result;
        return result.size();
    }
};

int main()
{
    Solution s;
    s.lengthOfLastWord("Hello Worlf");
    system("pause");
}