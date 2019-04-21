class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def placePar(tmp : str ,rRemain : int, lRemain : int ):
            #print(tmp)
            if(rRemain == 0):
                i = 0
                tmp2 = ''
                while(i<lRemain):
                    tmp2 += ')'
                    i += 1
                ans.append(tmp+tmp2)
                return 
            else:
                if(rRemain==lRemain):
                    placePar(tmp+'(', rRemain-1, lRemain)
                else:
                    placePar(tmp+'(', rRemain-1, lRemain)
                    placePar(tmp+')', rRemain, lRemain-1)
        placePar('',n,n)
        return ans