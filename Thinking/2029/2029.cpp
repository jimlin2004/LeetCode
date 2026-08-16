#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        題意:
            玩石頭，Alice先玩
            當所有被移除的石頭數值總和被3整除時就輸了
            然後如果沒有石頭可以移除時，算Bob贏
        解題 (參考題解)
        1. 因為只問是否被3整除，所以所有數值可以轉成3個餘數空間 -> 0, 1, 2
        2. 數字彼此不重要，所以只統計cnt0, cnt1, cnt2的數量
        3. Alice不能選餘數0，否則直接輸
        4. 如果當前餘數是1，下一步無法選2
        5. 如果當前餘數是2，下一步無法選1
        6. 0不會改變餘數，只會換對方出牌

        先假設沒有0，
        Alice先手，所以Alice可以選:
                                          abababab...
            1. 最開始選1，如此石頭序列只能是 11212121...
            2. 最開始選2，如此石頭序列只能是 22121212...
        重要觀察:
        1. 如果Alice選1，Bob只能一直出1
        2. 如果Alice選2，Bob只能一直出2
        所以cnt1或cnt2哪邊少，Alice選哪邊Bob就會輸

        因為0只是交換先後手，所以用cnt0分兩種狀況
        if (cnt0 是 偶數)
            1. 此時先後手關係不會改變(因為雙方可以一直打0)
            2. 如果cnt1 == 0
                + Alice第一手只能出2，Bob接下來也只有2能出，(2 + 2) % 3 = 1
                  下一回合Alice只能出2 -> 被3整除，Alice輸
               如果cnt2 == 0
                + Alice第一手只能出1，Bob接下來也只有1能出，(1 + 1) % 3 = 2
                  下一回合Alice只能出1 -> 被3整除，Alice輸
               如果 cnt1 == 0 and cnt2 == 0
                + Alice第一手就沒得出 -> Alice輸
            所以結論 -> (cnt1 >= 1 && cnt2 >= 2)時Alice贏
        if (cnt0 是 奇數)
            1. 奇數個0說明出石頭會反轉一次
            2. 假設Alice一樣出1開局，Bob在中途丟出一個0
                -> 換Alice承受缺石頭的壓力，所以Alice必須多出一個1的石頭
               假設Alice一樣出2開局也是同理
            因此只有abs(cnt1 - cnt2) >= 3的情況下
            Alice才能在Bob有出一次0的情況下還能贏 (回到cnt0是偶數的情況，因為多出來的石頭0被Bob出掉)
            Alice會選比較多的石頭
            必勝條件為abs(cnt1 - cnt2) > 2
    */
    bool stoneGameIX(vector<int>& stones)
    {
        int cnt[3] = {0, 0, 0};
        for (int val: stones)
            ++cnt[val % 3];
        
        if (cnt[0] % 2 == 0)
            return (cnt[1] >= 1 && cnt[2] >= 1);
        // cnt[0]是奇數
        return abs(cnt[1] - cnt[2]) > 2;
    }
};