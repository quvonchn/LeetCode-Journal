class Solution:
    # Xato: def minimumAbsDifference(arr):
    # To'g'ri:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
    
    
        min_diff = float('inf')
        result = []
    
    # 2. Eng kichik farqni (min_diff) aniqlash
        for i in range(len(arr) - 1):
            diff = arr[i+1] - arr[i]
            if diff < min_diff:
                min_diff = diff
            
    # 3. Shu farqqa ega juftliklarni yig'ish
        for i in range(len(arr) - 1):
            if arr[i+1] - arr[i] == min_diff:
                result.append([arr[i], arr[i+1]])
            
        return result
        