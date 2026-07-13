#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate_all(int curr, int start, vector<int>& res)
    {
        if (start >= 10)
            return;
        if (curr == 0)
        {

            for (int i = start; i < 10; ++i)
            {
                int newNum = curr * 10 + i;
                res.push_back(newNum);
            }

            for (int i = start; i < 10; ++i)
            {
                int newNum = curr * 10 + i;
                generate_all(newNum, i + 1, res);
            }
        }
        else
        {
            int newNum = curr * 10 + start;
            res.push_back(newNum);
            generate_all(newNum, start + 1, res);
        }
    }

    // 水題，然後其實可能性很少，可以直接手動枚舉
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> allNumbers;

        generate_all(0, 1, allNumbers);

        // 沒想到怎麼避免sort
        sort(allNumbers.begin(), allNumbers.end());

        vector<int> res;
        for (int val: allNumbers)
        {
            if (val > high)
                break;
            if (val >= low)
                res.emplace_back(val);
        }

        return res;
    }
};