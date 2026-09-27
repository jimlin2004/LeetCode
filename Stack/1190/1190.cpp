#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 利用stack很好解決
    string reverseParentheses(string s) 
    {
        stack<string> sk;

        int n = s.size();

        string currString("");
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                sk.push(currString);
                currString.clear();
            }
            else if (s[i] == ')')
            {
                reverse(currString.begin(), currString.end());
                if (!sk.empty())
                {
                    currString = sk.top() + currString;
                    sk.pop();
                }
            }
            else
            {
                currString += s[i];
            }
        }

        return currString;
    }
};

int main()
{
    Solution sol;
    sol.reverseParentheses("((eqk((h))))");
}