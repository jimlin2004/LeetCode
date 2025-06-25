#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:

    // 順著做過去不好維護答案
    // 因為後面的lcm可以可以合併前面的結果
    // 所以改成stack的方式做就可以影響前面了
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        vector<int> res;

        for (int num: nums)
        {
            res.push_back(num);
            while (res.size() > 1)
            {
                int m = res.size();
                if (__gcd(res[m - 1], res[m - 2]) != 1)
                {
                    int lcm = ((long long)res[m - 1] * res[m - 2]) / __gcd(res[m - 1], res[m - 2]);
                    res.pop_back();
                    res.pop_back();
                    res.push_back(lcm);
                }
                else
                    break;
            }
        }

        return res;
    }
};


int main()
{
    vector<int> nums = {6,4,3,2,7,6,2};

    Solution S;
    S.replaceNonCoprimes(nums);

    return 0;
}