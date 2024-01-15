#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        this->count = isConnected.size();
        int len = isConnected.size();
        for (int i = 0; i < len; i++)
            this->parent[i] = -1;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (i == j)
                    continue;
                if (isConnected[i][j])
                    this->Union(i, j);
            }
        }
        return count;
    }
private:
    int parent[201];
    int count;

    int find(int x)
    {
        if (this->parent[x] < 0)
            return x;
        this->parent[x] = this->find(this->parent[x]);
        return this->parent[x];
    }

    void Union(int x, int y)
    {
        int r1 = this->find(x);
        int r2 = this->find(y);
        if (r1 == r2)
            return;
        int sum = this->parent[r1] + this->parent[r2];
        if (this->parent[r1] >= this->parent[r2])
        {
            this->parent[r1] = r2;
            this->parent[r2] = sum;
            this->count--;
        }
        else if (this->parent[r1] < this->parent[r2])
        {
            this->parent[r2] = r1;
            this->parent[r1] = sum;
            this->count--;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{1,1,0},{1,1,0},{0,0,1}};
    printf("%d", s.findCircleNum(v));

}