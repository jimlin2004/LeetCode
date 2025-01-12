#include <bits/stdc++.h>
using namespace std;

// class Solution 
// {
// public:
//     // O(n ^ 2)解法，非常之簡單
//     vector<int> minOperations(string boxes)
//     {
//         vector<int> res;
//         int n = boxes.size();
//         for (int i = 0; i < n; ++i)
//         {
//             int total = 0;
//             for (int j = 0; j < n; ++j)
//             {
//                 if (boxes[j] == '1')
//                     total += abs(i - j);
//             }
//             res.emplace_back(total);
//         }
//         return res;
//     }
// };

class Solution 
{
public:
    // 算是一邊轉移一邊算的前綴和
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        // 第0格的左邊有幾個1
        int left = 0;
        // 第0格左邊要幾步才能搬過來
        int leftCost = 0;
        // 第0格的右邊有幾個1
        int right = 0;
        // 第0格右邊要幾步才能搬過來
        int rightCost = 0;
        //算右邊
        for (int i = 1; i < n; ++i)
        {
            if (boxes[i] == '1')
            {
                ++right;
                rightCost += i;
            }
        }
        vector<int> res;
        res.emplace_back(rightCost);
        left += boxes[0] - '0';
        //開始轉移->轉移只要O(1)
        //所以整題O(n)即可
        for (int i = 1; i < n; ++i)
        {
            //右邊的全部少1步
            rightCost -= right;
            right -= boxes[i] - '0';
            //左邊的全部多1步
            leftCost += left;
            res.emplace_back(leftCost + rightCost);
            left += boxes[i] - '0';
        }
        return res;
    }
};