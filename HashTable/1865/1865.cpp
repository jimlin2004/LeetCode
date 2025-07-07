#include <bits/stdc++.h>
using namespace std;


class FindSumPairs 
{
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> cnt; // nums2中每種數字的數量

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
        : nums1(nums1), nums2(nums2)
    {
        for (int v: this->nums2)
            ++this->cnt[v];
    }
    
    void add(int index, int val) 
    {
        --this->cnt[this->nums2[index]];
        this->nums2[index] += val;
        ++this->cnt[this->nums2[index]];
    }
    
    int count(int tot) 
    {
        int res = 0;
        // 直接暴力迭代nums1在cnt中找tot - v
        // 因為nums1最多只有1000個
        for (int v: this->nums1)
        {
            res += this->cnt[tot - v];
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */