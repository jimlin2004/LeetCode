#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        vector<char>* vec = new vector<char>[numRows];
        int i = 0, c = numRows;
        while (i < s.size())
        {
            c = 0;
            for (int j = 0; j < numRows; j++)
            {
                vec[j].push_back(s[i]);
                i++;
            }
            while (c > 0)
            {
                
            }
        }
    }
};