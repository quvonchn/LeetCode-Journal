class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        l=0
        r=len(nums)-1
        maxi=0
        while l<r:
            maxi=max(maxi,nums[l]+nums[r])
            l+=1
            r-=1
        return maxi