#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) 
    {
        int num_table[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4,  1};
        string char_table[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int n;
        scanf("%d", &n);
        int i = 0;
        string result = "";
        while (n > 0)
        {
            printf("%d\n", i);
            while (n >= num_table[i])
            {
                n -= num_table[i];
                result += char_table[i];
            }
            i++;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(3);
}