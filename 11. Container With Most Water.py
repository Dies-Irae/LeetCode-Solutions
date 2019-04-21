class Solution:
    def maxArea(self, height: List[int]) -> int:
        mx = 0
        i = 0
        j = len(height) - 1
        while i != j:
            tmp = (j-i)*min(height[i],height[j])
            #print(tmp)
            if mx < tmp:
                mx = tmp
            if height[i] > height[j]:
                j -= 1
            else:
                i += 1
        return mx