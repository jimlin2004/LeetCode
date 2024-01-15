#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        this->prefix_sum[0] = arr[0];
        for (int i = 1; i < arr.size(); i++)
            this->prefix_sum[i] = this->prefix_sum[i - 1] + arr[i];
        int n = 1;
        int ans = 0;
        int fast = 0;
        int limit = arr.size();
        while (n <= limit)
        {
            for (int slow = 0; slow < limit; slow++)
            {
                fast = slow + n;
                if (fast > limit)
                    break;
                if (slow == 0)
                    ans += this->prefix_sum[fast - 1];
                else
                    ans += (this->prefix_sum[fast - 1] - this->prefix_sum[slow - 1]);
                // printf("ans=%d slow=%d fast=%d\n", ans, slow, fast);
            }
            n += 2;
        }
        return ans;
    }
private:
    int prefix_sum[100];
};