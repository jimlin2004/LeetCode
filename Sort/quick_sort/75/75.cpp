#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        this->quick_sort(nums, 0, nums.size() - 1);
    }
private:
    int partition(vector<int>& nums, int l ,int r)
    {
        int pivot = nums[l]; //統一取頭
        int count = 0;
        for (int i = l + 1; i <= r; i++)
        {
            if (nums[i] <= pivot)
                count++;
        }
        int pivot_idx = l + count;
        swap(nums[pivot_idx], nums[l]);
        int i = l, j = r;
        while (i < pivot_idx && j > pivot_idx)
        {
            while (nums[i] <= pivot)
                i++;
            while (nums[j] > pivot)
                j--;
            if (i < pivot_idx && j > pivot_idx)
                swap(nums[i++], nums[j--]);
        }
        return pivot_idx;
    }

    void quick_sort(vector<int>& nums, int l, int r)
    {
        if (l >= r)
            return;
        int p = this->partition(nums, l, r);
        this->quick_sort(nums, l, p - 1);
        this->quick_sort(nums, p + 1, r);
    }
};