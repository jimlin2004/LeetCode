#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        this->backTracking(1, n);
        return this->res;
    }
private:
    int queen[10]; //col
    vector<vector<string>> res;

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
            vector<string> vec;
            for (int i = 1; i <= n; i++)
            {
                string str(n, '.');
                str[queen[i] - 1] = 'Q';
                vec.push_back(str);
            }
            this->res.push_back(vec);
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