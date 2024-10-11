#include <string>
using namespace std;


class Solution 
{
public:
    string largestOddNumber(string num) 
    {
        //找最右邊的奇數
        int oddPos;
        for (oddPos = num.size() - 1; oddPos >= 0; --oddPos)
        {
            if ((num[oddPos] - '0') & 1)
                break;
        }
        //前面全部選
        return num.substr(0, oddPos + 1);
    }
};