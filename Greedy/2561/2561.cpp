#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        經典greedy之一
        由於要讓兩邊一樣
        所以要先檢查是否可能
        也就是每一種水果的數量要能被二整除
        再來由於水果交換的cost是min(x, y)
        所以直覺上來看最賺的方式就是拿最便宜的水果換最貴的水果
        但還要另外考慮一種可能
        也就是拿所有水果裡最便宜的 minX
        去換x跟y
        此時成本是2 * minX
        所以解法就是找出哪些水果要換
        然後每次都選擇用 最便宜的水果換最貴的 或是 拿minX取換x、y

        基本上有點類似過橋問題的解法
    */
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        unordered_map<int, int> total;
        for (int fruit: basket1)
            ++total[fruit];
        for (int fruit: basket2)
            ++total[fruit];
        
        int minFruit = 0x3f3f3f3f; // 所有水果裡面最便宜的
        for (auto& [fruit, cnt]: total)
        {
            if (cnt & 1)
                return -1;
            minFruit = min(minFruit, fruit);
        }

        unordered_map<int, int> cnt1; // basket1的水果數量
        for (int fruit: basket1)
            ++cnt1[fruit];

        vector<int> fruitToChange;

        for (auto& [fruit, cnt]: total)
        {
            // 這裡不用管basket1裡是多還是少，反正都要換
            int needToChangeCnt = abs(cnt1[fruit] - cnt / 2); // 算還有多少不平衡
            for (int i = 0; i < needToChangeCnt; ++i)
                fruitToChange.emplace_back(fruit);
        }

        // 方便計算最便宜換最貴
        // 此時拿當前最便宜的一定有個當前最貴的可以換
        // 因為不平衡的水果一定是偶數
        sort(fruitToChange.begin(), fruitToChange.end());

        long long minCost = 0;

        int len = fruitToChange.size() / 2;

        for (int i = 0; i < len; ++i)
        {
            // 每次選最便宜的換法
            minCost += min(fruitToChange[i], 2 * minFruit);
        }

        return minCost;
    }
};


int main()
{
    vector<int> B1 = {4, 2, 2, 2};
    vector<int> B2 = {1, 4, 1, 2};

    Solution S;
    S.minCost(B1, B2);

    return 0;
}