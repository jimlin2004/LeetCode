#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int parent[30];
    
    int findRoot(int x)
    {
        if (parent[x] < 0)
            return x;
        return parent[x] = findRoot(parent[x]);
    }

    bool Uni(int a, int b)
    {
        int r1 = findRoot(a);
        int r2 = findRoot(b);
        if (r1 == r2)
            return false;
        if (parent[r1] < parent[r2])
        {
            parent[r1] += parent[r2];
            parent[r2] = r1;
        }
        else
        {
            parent[r2] += parent[r1];
            parent[r1] = r2;
        }
        return true;
    }
    
    //簡單題，用並查集去判不相同卻在同一個環的就不行，其餘可以
    bool equationsPossible(vector<string>& equations) 
    {
        memset(parent, -1, sizeof(parent));

        vector<pair<int, int>> diffPairs;
        for (string& equation: equations)
        {
            if (equation[1] == '=')
                Uni(equation[0] - 'a', equation[3] - 'a');
            else
                diffPairs.emplace_back(equation[0] - 'a', equation[3] - 'a');
        }
        
        for (pair<int, int>& p: diffPairs)
        {
            //是不是在同一個環
            if (findRoot(p.first) == findRoot(p.second))
                return false;
        }
        return true;
    }
};