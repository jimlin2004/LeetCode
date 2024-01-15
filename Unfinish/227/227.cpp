#include <string>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int calculate(string s) 
    {
        this->getRPN(s);
        return this->evalRPN();
    }
private:
    queue<string> RPN;

    int getPriority(char c)
    {
        switch (c)
        {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;

        default:
            break;
        }
        return 0;
    }

    void getRPN(const string& str)
    {
        stack<char> sk;

        for (int i = 0; i < str.size(); ++i)
        {
            if (isdigit(str[i]))
            {
                string num = "";
                while (isdigit(str[i]))
                {
                    num += str[i];
                    ++i;
                }
                --i; // 因為str[i]不是數字
                RPN.push(num);
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                if (sk.empty())
                    sk.push(str[i]);
                else
                {
                    while (!sk.empty() && getPriority(sk.top()) >= getPriority(str[i]))
                    {
                        RPN.push({sk.top()});
                        sk.pop();
                    }
                    sk.push(str[i]);
                }
            }
        }

        while (!sk.empty())
        {
            RPN.push({sk.top()});
            sk.pop();
        }
    }

    int evalRPN()
    {
        stack<int> sk;
        string op;
        while (!this->RPN.empty())
        {
            op = this->RPN.front();
            this->RPN.pop();
            if (isdigit(op[0]))
            {
                sk.push(stoi(op));
            }
            else
            {
                switch (op[0])
                {
                case '+':
                {
                    int a = sk.top();
                    sk.pop();
                    int b = sk.top();
                    sk.pop();
                    sk.push(b + a);
                    break;
                }
                case '-':
                {
                    int a = sk.top();
                    sk.pop();
                    int b = sk.top();
                    sk.pop();
                    sk.push(b - a);
                    break;
                }
                case '*':
                {
                    int a = sk.top();
                    sk.pop();
                    int b = sk.top();
                    sk.pop();
                    sk.push(b * a);
                    break;
                }
                case '/':
                {
                    int a = sk.top();
                    sk.pop();
                    int b = sk.top();
                    sk.pop();
                    sk.push(b / a);
                    break;
                }
                default:
                    break;
                }
            }
        }
        return sk.top();
    }
};

int main()
{
    string expression;
    while (getline(cin, expression))
    {
        Solution solution;
        cout << solution.calculate(expression) << '\n';
    }
    return 0;
}