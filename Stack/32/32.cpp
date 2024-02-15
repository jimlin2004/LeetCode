#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        /*
            概念: 
            (() -> X()
            ()()) -> ()()X
            ()()((()) -> ()()X(())
            將不合法標記為X，再scan一次算不包含X的最長子字串
            要O(n + n)
            改進用stack把不合法的index紀錄在stack
            而在下面算法中sk.pop後sk為empty時我們知道是一個新句子的開始
            所以也要push index(也就是遇到 "...)"，多一個')')
        */
        stack<int> sk;
        int res = 0;
        //for 第一個合法的開始ex: -1() -> 下面算法長度為二
        //也就是創造一個不合格的X
        sk.push(-1);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                sk.push(i);
            }
            else
            {
                sk.pop();
                if (sk.empty())
                    sk.push(i);
                else
                    res = max(res, i - sk.top());
            }
        }
        return res;
    }
};