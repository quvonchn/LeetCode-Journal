class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        # 1-qadam: Massivni o'sish tartibida joylashtiramiz
        nums.sort()
        
        # O'zgaruvchilarni tayyorlaymiz
        max_sum = 0
        n = len(nums)
        
        # 2-qadam: Faqat yarimigacha aylanamiz (n / 2)
        # Chunki har safar bitta boshidan, bitta oxiridan olamiz
        for i in range(n // 2):
            # Eng kichik (i) + Eng katta (n - 1 - i)
            current_sum = nums[i] + nums[n - 1 - i]
            
            # Agar hozirgi yig'indi oldingisidan katta bo'lsa, uni eslab qolamiz
            max_sum = max(max_sum, current_sum)
            
        return max_sum
        