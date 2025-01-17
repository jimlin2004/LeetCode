class Solution 
{
public:
    //非常無聊的題
    //只要從最高位bit開始消，還有剩下就從最低位開始看能不能填bit上去
    int minimizeXor(int num1, int num2) 
    {
        int oneOfNum2Cnt = 0;
        while (num2)
        {
            oneOfNum2Cnt += (num2 & 1);
            num2 >>= 1;
        }
        unsigned int mask = 1 << 31;
        int res = 0;
        while (oneOfNum2Cnt && mask)
        {
            if (num1 & mask)
            {
                res |= mask;
                --oneOfNum2Cnt;
            }
            mask >>= 1;
        }
        mask = 1;
        while (oneOfNum2Cnt)
        {
            if ((res & mask) == 0)
            {
                res |= mask;
                --oneOfNum2Cnt;
            }
            mask <<= 1;
        }
        return res;
    }
};