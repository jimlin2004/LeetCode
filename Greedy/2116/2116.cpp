#include <bits/stdc++.h>
using namespace std;

#define use_1 1
class Solution 
{
public:
    /*
        這題有點棘手(Greedy)
        結論: 
            只要討論括號匹配的可能性存在就一定能找到
            正確的括號，不用討論過程的字串奇偶數
        如何檢查:
            由左到右維護最大可能的'('數量[leftCntMax]
            若出現leftCntMax < 0就不可能
            還要從右到左再檢查一遍維護最大可能的')'數量[rightCntMax]
            若出現rightCntMax < 0就不可能
        為什麼不用討論過程的字串奇偶數問題?
            1. 字串一定要是even，否則不可能
            2. 若字元沒被固定，可以選擇要是'('或')'
            !!! 若過程中出現了不能匹配的括號，一定是一個unlocked括號引起的
            所以只要檢查的過程中沒有出現leftCntMax < 0的情況
            我們就能透過調整unlocked做到正確的字串
    */
    #if use_1
    bool canBeValid(string s, string locked) 
    {
        int n = s.size();
        if (n & 1) //長度odd不可能
            return false;
        
        //左到右
        //左邊最多可以有幾個 '('
        int leftCntMax = 0;
        for (int i = 0; i < n; ++i)
        {
            if (locked[i] == '0')
                ++leftCntMax;
            else
            {
                if (s[i] == '(')
                    ++leftCntMax;
                else
                    --leftCntMax;
            }
            if (leftCntMax < 0)
                return false;
        }
        //右到左
        //右邊最多可以有幾個 ')'
        int rightCntMax = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (locked[i] == '0')
                ++rightCntMax;
            else
            {
                if (s[i] == ')')
                    ++rightCntMax;
                else
                    --rightCntMax;
            }
            if (rightCntMax < 0)
                return false;
        }
        return true;
    }
    
    #else
    // 只要1個loop的版本
    bool canBeValid(string s, string locked) 
    {
        int n = s.size();
        if (n & 1) //長度odd不可能
            return false;
        
        int leftCntMax = 0; //最多左邊幾個'('
        int leftCntMin = 0; //最少左邊幾個'('
        for (int i = 0; i < n; ++i)
        {
            if (locked[i] == '1')
            {
                if (s[i] == '(')
                {
                    ++leftCntMax;
                    ++leftCntMin;
                }
                else
                {
                    --leftCntMax;
                    --leftCntMin;
                }
            }
            else
            {
                ++leftCntMax; //當作'('
                --leftCntMin; //當作')'
            }
            if (leftCntMin < 0)
                leftCntMin = 0; //可以透過調整unlocked得到0
            if (leftCntMax < 0)
                return false;
        }
        return (leftCntMin == 0); //檢查有沒有多出來匹配不了的
    }
    #endif
};