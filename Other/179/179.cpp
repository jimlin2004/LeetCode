#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string largestNumber(vector<int>& nums) 
    {
        for (int n: nums)
            this->add_to_pq(n);
        string res = "";
        while (!this->pq.empty())
        {
            res += (char)('0' + this->pq.top());
            this->pq.pop();
        }
        return res;
    }
private:
    priority_queue<int> pq;
    void add_to_pq(int n)
    {
        while (n >= 10)
        {
            this->pq.push(n % 10);
            n /= 10;
        }
        this->pq.push(n);
        return;
    }
};