#include <bits/stdc++.h>
using namespace std;

// 資結選一下就能過了
class NumberContainers 
{
public:
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> numIndices;

    NumberContainers() 
    {
        
    }

    void change(int index, int number) 
    {
        int oldElement = mp[index];
        if (oldElement != 0) // 那個位置有人了
        {
            numIndices[oldElement].erase(index);
        }
        mp[index] = number;
        numIndices[number].insert(index);
    }
    
    int find(int number) 
    {
        auto& indices = numIndices[number];
        if (indices.empty())
            return -1;
        return (*indices.begin());
    }
};