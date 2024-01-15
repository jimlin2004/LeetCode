#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        for (int n: stones)
            pq.push(n);
        int n1, n2;
        while (pq.size() > 1)
        {
            n1 = pq.top();
            pq.pop();
            n2 = pq.top();
            pq.pop();
            pq.push(n1 - n2);
        }
        return pq.top();
    }
private:
    priority_queue<int> pq;
};