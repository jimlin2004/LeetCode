#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //爛題目，不過說不定可以用有限狀態機去寫
    int myAtoi(string s) 
    {
        string bigNum = "";
        bool startReadNum = false;
        bool negative = false;
        bool isLeadZero = true;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                if (startReadNum)
                    break;
            }
            else if (s[i] == '-')
            {
                if (startReadNum)
                    break;
                negative = true;
                startReadNum = true;
            }
            else if (s[i] == '+')
            {
                if (startReadNum)
                    break;
                startReadNum = true;
            }
            else if (s[i] == '0')
            {
                if (startReadNum && !isLeadZero)
                    bigNum += s[i];
                startReadNum = true;
            }
            else if ('1' <= s[i] && s[i] <= '9')
            {
                startReadNum = true;
                isLeadZero = false;
                bigNum += s[i];
            }
            else
                break;
        }
        string upperBound = "2147483647";
        string lowerBound = "2147483648"; //負的，但我拿掉了
        if (bigNum.empty())
            return 0;
        //一定越界
        if (bigNum.size() > 10)
        {
            if (negative)
                return -2147483648; //用lowerBound去轉會超出去
            return stoi(upperBound);
        }
        //檢查是否越界
        if (bigNum.size() == 10)
        {
            if (negative)
            {
                if (bigNum >= lowerBound)
                    return -2147483648; //用lowerBound去轉會超出去
            }
            if (bigNum > upperBound)
                return stoi(upperBound);
        }
        if (negative)
            return -stoi(bigNum);
        return stoi(bigNum);
    }
};