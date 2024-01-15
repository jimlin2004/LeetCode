#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        this->merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    int oo = 99999999;
    void merge(vector<int>& nums, int l, int mid, int r)
    {
        vector<int> leftsub(nums.begin() + l, nums.begin() + mid + 1),
                    rightsub(nums.begin() + mid + 1, nums.begin() + r + 1);
        leftsub.push_back(this->oo);
        rightsub.push_back(this->oo);
        int idx_l = 0, idx_r = 0;
        for (int i = l; i <= r; i++)
        {
            if (leftsub[idx_l] <= rightsub[idx_r])
            {
                nums[i] = leftsub[idx_l];
                idx_l++;
            }
            else
            {
                nums[i] = rightsub[idx_r];
                idx_r++;
            }
        }
    }

    void merge_sort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        this->merge_sort(nums, l, mid);
        this->merge_sort(nums, mid + 1, r);
        this->merge(nums, l, mid, r);
    }
};