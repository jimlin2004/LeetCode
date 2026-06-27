#include <bits/stdc++.h>
using namespace std;


// 就存到map然後枚舉答案
class Solution
{
private:
    // mp[key] = {count, vis}
    map<int, pair<int, bool>> mp;
public:
    int maximumLength(vector<int>& nums)
    {
        for (int val: nums)
        {
            auto it = mp.find(val);
            if (it == mp.end())
            {
                mp[val] = make_pair(1, false);
            }
            else
            {
                ++(it->second.first);
            }
        }

        int res = 1; // 至少一個
        int currLen = 0;
        for (auto mpPair: mp)
        {
            if (mpPair.first == 1) // 1要特判
            {
                res = max(res, mpPair.second.first - (mpPair.second.first % 2 == 0));
                continue;
            }
            if (!mpPair.second.second)
            {
                mpPair.second.second = true;

                currLen = 0;
                long long currVal = mpPair.first;
                while (1)
                {
                    auto it = mp.find(currVal);
                    if (it != mp.end())
                    {
                        if (it->second.first >= 2) // 可以繼續，也有可能當作中間那一個
                            currLen += 2;
                        else if (it->second.first == 1) // 遇到中間那一個
                        {
                            currLen += 2; // 都先當兩個
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                    if (currVal > INT_MAX)
                        break;
                    currVal *= currVal;
                }

                res = max(res, currLen - 1); // 扣掉中間那一個沒有多
            }
        }

        return res;
    }
};

int main()
{
    Solution S;
    vector<int> nums = {5, 4, 1, 2, 2};
    S.maximumLength(nums);

    return 0;
}