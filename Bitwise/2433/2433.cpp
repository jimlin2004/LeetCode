#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> findArray(vector<int>& pref)
    {
        vector<int> res;
        int prev = 0;
        for (int i = 0; i < pref.size(); ++i)
        {
            res.emplace_back(pref[i] ^ prev);
            prev = pref[i];
        }
        return res;
    }
};