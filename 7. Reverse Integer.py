class Solution:
    def reverse(self, x: int) -> int:
        if(x >= 0):
            y=list(str(x))
            y.reverse()
            ans = int ("".join(y) )
        else:
            y=list(str(-x))
            y.reverse()
            ans = -int ("".join(y) )
        if(ans >= 2**31 or ans < -2**31):
            return 0
        else:
            return ans