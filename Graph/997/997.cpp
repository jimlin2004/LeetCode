#include <vector>
using namespace std;

class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<bool> trustToOther(n + 1, false);
        vector<int> beTrusted(n + 1, 0);
        for (int i = 0; i < trust.size(); i++)
        {
            trustToOther[trust[i][0]] = true;
            beTrusted[trust[i][1]]++;
        }
        for (int i = 1; i < beTrusted.size(); i++)
        {
            if (beTrusted[i] == n - 1 && trustToOther[i] == false)
                return i;
        }
        return -1;
    }
};