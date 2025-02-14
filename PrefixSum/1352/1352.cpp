#include <bits/stdc++.h>
using namespace std;

#define maxn 40005

// 考特殊的prefix product array用法
class ProductOfNumbers 
{
public:
    unsigned long long prefix[maxn];
    unsigned int ptr;

    ProductOfNumbers() 
    {
        memset(prefix, 0, sizeof(prefix));
        // 從第1格開始
        prefix[0] = 1;
        ptr = 1;
    }
    
    void add(int num) 
    {
        // 如果出現0
        // 代表在那之前的prefix查詢出來都是0
        // 所以可以等於重置所有的prefix
        // (因為題目只會從後面開始查詢)
        if (num == 0)
        {
            ptr = 1;
        }
        else
        {
            prefix[ptr] = prefix[ptr - 1] * num;
            ++ptr;
        }
    }
    
    int getProduct(int k) 
    {
        if (ptr <= k)
            return 0;
        return prefix[ptr - 1] / prefix[ptr - k - 1];
    }
};