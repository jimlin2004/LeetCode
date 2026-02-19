#include <bits/stdc++.h>
using namespace std;


/*
    題目說的是第二個分段開頭的index與最後一個分段的index要在dist的距離以內
    且題意是要將arr分成k段有最小成本
    這時候第一個數字必選，否則無法覆蓋第一個元素

    所以題目變成找第二個分段的起始index j且往後一段區間中(j ~ j + dist)
    有最小成本的k - 1個分段

    ex: [ 1, 3, 2, 6, 4, 2 ], k = 3, dist = 3
             j        v      
        則答案為 1 + 3 + 2 = 6
                j        v
        則答案為 1 + 2 + 2 = 5
    
    所以題目的重點就是滑動窗戶(size = dist)維護k - 1個最小的數字和
    困難點在於怎麼高效的轉移窗戶?
    解法是兩個heap + lazy update
    如此可以做到O(nlogn)
*/
class Solution
{
public:
    long long minimumCost(vector<int>& nums, int k, int dist)
    {
        int n = nums.size();

        --k; // 因為第一個數字一定會選

        long long minCost = 0x3f3f3f3f3f3f3f3f;
        long long windowSum = 0;

        // 窗戶內被選擇的k - 1個最小數字
        // 用max heap方便判斷目前的新數字是否比之前選得更小 (top 是k - 1個中的最大)
        priority_queue<long long, vector<long long>, less<long long>> usedPQ;
        // 窗戶內沒有被選擇的數字
        // 用min_heap方便隨時從備取數字中拿出最小的
        priority_queue<long long, vector<long long>, greater<long long>> unusedPQ;
    
        // lazy update使用
        // 紀錄<數字, 要刪幾次>
        unordered_map<long long, int> lazyMP_used;
        unordered_map<long long, int> lazyMP_unused;

        // 紀錄PQ中真正存在的數字(不含應該lazy update掉的數字)
        int usedSize = 0;
        int unusedSize = 0;

        // 實際update，將heap頂部應該要刪除的數字都刪除
        auto cleanHeap = [&](auto& heap, auto& lazyMP){
            while (!heap.empty() && lazyMP[heap.top()] > 0)
            {
                --lazyMP[heap.top()];
                heap.pop();
            }
        };

        auto balance = [&](){
            // 取值之前要先確保不是應該要刪除的值
            cleanHeap(usedPQ, lazyMP_used);
            cleanHeap(unusedPQ, lazyMP_unused);

            // 當usedPQ數字太多的時候，將數字移去unusedPQ當備取
            while (usedSize > k)
            {
                // 取值之前要先確保不是應該要刪除的值
                cleanHeap(usedPQ, lazyMP_used);
                long long val = usedPQ.top();
                usedPQ.pop();
                --usedSize;
                windowSum -= val;

                unusedPQ.push(val);
                ++unusedSize;
            }
            
            // 當usedPQ數字不夠的時候，從unusedPQ補
            while (usedSize < k && unusedSize > 0)
            {
                // 取值之前要先確保不是應該要刪除的值
                cleanHeap(unusedPQ, lazyMP_unused);

                long long val = unusedPQ.top();
                unusedPQ.pop();
                --unusedSize;

                usedPQ.push(val);
                windowSum += val;
                ++usedSize;
            }

            

            // 確保usedPQ的值比unusedPQ的都還要小
            while (usedSize > 0 && unusedSize > 0)
            {
                // 先確保heap的頂部都是可以用的數字
                cleanHeap(usedPQ, lazyMP_used);
                cleanHeap(unusedPQ, lazyMP_unused);

                if (usedPQ.top() > unusedPQ.top())
                {
                    long long usedVal = usedPQ.top();
                    usedPQ.pop();
                    long long unusedVal = unusedPQ.top();
                    unusedPQ.pop();

                    // 交換
                    usedPQ.push(unusedVal);
                    unusedPQ.push(usedVal);
                    windowSum = windowSum - usedVal + unusedVal;
                }
                else
                    break;
            }
        };


        // 開始滑動窗戶

        // 先初始化窗戶
        for (int i = 1; i <= min(n - 1, 1 + dist); ++i)
        {
            usedPQ.push(nums[i]);
            windowSum += nums[i];
            ++usedSize;
        }
        balance(); // 上面的窗戶可能超過k - 1個數字了，要調整

        minCost = windowSum;

        // 開始滑
        for (int i = 1; i < n; ++i)
        {
            if (i + dist + 1 >= n)
                break;
            
            long long out = nums[i];
            long long in = nums[i + dist + 1];

            // 判斷out是不是在used裡面
            cleanHeap(usedPQ, lazyMP_used);
            if (usedSize > 0 && !usedPQ.empty() && out <= usedPQ.top())
            {
                // 目前要刪除的數字比usedPQ中最大的還小，就代表out還是被算在windowSum裡面
                ++lazyMP_used[out];
                windowSum -= out;
                --usedSize;
            }
            else
            {
                ++lazyMP_unused[out];
                --unusedSize;
            }

            // 加入新數字，統一丟到used，後面balance再處理
            usedPQ.push(in);
            windowSum += in;
            ++usedSize;

            balance();

            minCost = min(minCost, windowSum);
        }

        return (long long)nums[0] + minCost;
    }
};


int main()
{
    Solution S;
    vector<int> nums = {1,3,2,6,4,2};
    S.minimumCost(nums, 3, 3);
}