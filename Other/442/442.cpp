#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        memset(this->appeared, false, sizeof(bool) * 100000);
        vector<int> ans;
        for (int n: nums)
        {
            if (this->appeared[n])
                ans.push_back(n);
            else
                this->appeared[n] = true;
        }
        return ans;
    }
private:
    bool appeared[100000];
};