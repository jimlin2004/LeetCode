#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        for (int n: nums)
            pg.push(n);
        int n1, n2;
        n1 = pg.top();
        pg.pop();
        n2 = pg.top();
        return (n1 - 1) * (n2 - 1); 
    }
private:
    priority_queue<int> pg;
};