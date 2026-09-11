#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNumbers(vector<int>& digits)
    {
        unordered_map<int, bool> mp; 

        int n = digits.size();

        // 枚舉所有3個數字
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    int val = digits[i] * 100 + digits[j] * 10 +digits[k];
                    if (val % 2 == 0 && val >= 100)
                        mp[val] = true;
                    val = digits[i] * 100 +digits[k] * 10 + digits[j];
                    if (val % 2 == 0 && val >= 100)
                        mp[val] = true;
                    val = digits[j] * 100 + digits[i] * 10 +digits[k];
                    if (val % 2 == 0 && val >= 100)
                        mp[val] = true;
                    val = digits[j] * 100 +digits[k] * 10 + digits[i];
                    if (val % 2 == 0 && val >= 100)
                        mp[val] = true;
                    val =digits[k] * 100 + digits[i] * 10 + digits[j];
                    if (val % 2 == 0 && val >= 100)
                        mp[val] = true;
                    val =digits[k] * 100 + digits[j] * 10 + digits[i];
                    if (val % 2 == 0 && val >= 100)
                        mp[val] = true;
                }
            }
        }

        return mp.size();
    }
};