#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int maxDepth(string s) 
    {
        int res = 0;
        //左括號數量
        int leftCount = 0;
        for (char c: s)
        {
            if (c == '(')
            {
                ++leftCount;
            }
            else if (c == ')')
            {
                res = max(res, leftCount);
                --leftCount;
            }
        }
        return res;
    }
};