#include <bitset>
using namespace std;

class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        bitset<32> xorBits(x ^ y); // ^ is xor
        return xorBits.count();
    }
};