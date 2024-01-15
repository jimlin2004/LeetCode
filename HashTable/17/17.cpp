#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits == "")
            return this->result;
        this->combine("", 0, digits.size(), digits);
        return this->result;
    }

    //https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/1454778/using-recursion-in-C%2B%2B-or-100-faster
    void combine(string str, int i, int n, string digits)
    {
        if (i == n)
        {
            this->result.push_back(str);
            return;
        }
        char temp = digits[i];
        for (auto c: this->table[temp])
            this->combine(str + c, i + 1, n, digits);
    }
private:
    unordered_map<char, vector<char> > table = {
        {'1', {}},
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    vector<string> result;
};