class Solution 
{
public:
    bool canWinNim(int n) 
    {
        //4以下必贏
        if (n < 4)
            return true;
        //4的倍數必輸
        return (n % 4 != 0);
    }
};