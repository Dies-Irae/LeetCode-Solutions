class Solution:
    def convert(self, s: str, numRows: int) -> str:
        table = ["" for _ in range(numRows)]
        r = 0
        down = True
        if numRows == 1:
            return s
        for char in s:
            print(r)
            table[r] += char
            if(down):
                r += 1
            else:
                r -= 1
            if(r == 0):
                down = True
            elif(r == numRows-1):
                down = False
        ans = ""
        for string in table:
            ans += string
        return ans
        