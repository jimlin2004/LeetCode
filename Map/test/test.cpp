#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> dict;
    dict.insert({1, 200});
    dict.insert({0, 100});
    dict.insert({100, 0});
    for (auto i = dict.begin(); i != dict.end(); i++)
    {
        cout << i->first << ' ' << i->second << '\n';
    }
    system("pause");
    return 0;
}