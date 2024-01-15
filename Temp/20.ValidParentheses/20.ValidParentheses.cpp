#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
    {
        for (char c: s)
        {
            if (c == '(' || c == '[' || c == '{')
                this->buffer.push(c);
            else
            {
                if (this->buffer.empty() || (c != ')' && this->buffer.top() == '(') || (c != ']' && this->buffer.top() == '[') || (c != '}' && this->buffer.top() == '{'))
                    return false;
                this->buffer.pop();
            }
        }
        return this->buffer.empty();
    }
private:
    stack<char> buffer;
};