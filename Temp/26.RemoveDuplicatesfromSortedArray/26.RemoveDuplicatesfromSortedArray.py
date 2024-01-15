class Solution:
    def removeDuplicates(self, nums) -> int:
        nums.sort()
        result = list(set(nums))
        print(result)
        return len(result)

s = Solution()
print(s.removeDuplicates([1,1,2]))