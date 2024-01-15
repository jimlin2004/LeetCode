#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int totalNQueens(int n)
    {
        this->res = 0;
        this->backTracking(1, n);
        return this->res;
    }
private:
    int queen[10]; //col
    int res;

    bool check(int c, int r)
    {
        for(int i = 1; i < r; i++)
        {
            if (queen[i] == c)
                return false;
            if (abs(i - r) == abs(queen[i] - c))
                return false;
        }
        return true;
    }

    void backTracking(int r, int n)
    {
        if (r > n)
        {
            this->res++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (this->check(i, r))
            {
                this->queen[r] = i;
                this->backTracking(r + 1, n);
            }
        }
    }
};