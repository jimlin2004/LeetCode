#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0 && n == 1)
            nums1[0] = nums2[0];
        else
        {
            int index_nums2 = 0;
            for (int i = 0; i < m + n; i++)
            {
                if (nums1[i] == 0)
                {
                    nums1[i] = nums2[index_nums2];
                    index_nums2++;
                }
            }
            this->merge_sort(nums1, 0, nums1.size() - 1);
        }
        return;
    }
private:
    int oo = 99999999;
    void merge_sort(vector<int>& nums1, int l, int r)
    {
        if (l >= r)
            return;
        int mid = (l + r) >> 1;
        this->merge_sort(nums1, l, mid);
        this->merge_sort(nums1, mid + 1, r);
        this->Merge(nums1, l, mid, r);
        return;
    }
    void Merge(vector<int>& nums1, int l, int mid, int r)
    {
        vector<int> leftsub(nums1.begin() + l, nums1.begin() + mid + 1),
                    rightsub(nums1.begin() + mid + 1, nums1.begin() + r + 1);
        leftsub.insert(leftsub.end(), this->oo);
        rightsub.insert(rightsub.end(), this->oo);
        int index_f = 0, index_r = 0;
        for (int i = l; i <= r; i++)
        {
            if (leftsub[index_f] <= rightsub[index_r])
            {
                nums1[i] = leftsub[index_f];
                index_f++;
            }
            else
            {
                nums1[i] = rightsub[index_r];
                index_r++;
            }
        }
        return;
    }
};

int main()
{
    vector<int> nums1 = {0,0,0,0,0}, nums2 = {1,2,3,4,5};
    int m = 0, n = 5;
    Solution s;
    s.merge(nums1, m, nums2, n);
    return 0;
}