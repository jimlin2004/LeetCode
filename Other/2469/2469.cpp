#include <vector>
using namespace std;

class Solution 
{
public:
    vector<double> convertTemperature(double celsius) 
    {
        return {celsius + 273.1500, celsius * 1.80 + 32.00};
    }
};