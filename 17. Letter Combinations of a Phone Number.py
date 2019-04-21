class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == '':
            return []
        numdict = {'2':['a','b','c'],
                   '3':['d','e','f'],
                   '4':['g','h','i'],
                   '5':['j','k','l'],
                   '6':['m','n','o'],
                   '7':['p','q','r','s'],
                   '8':['t','u','v'],
                   '9':['w','x','y','z'],
                  }
        ans=[]
        def numplace(remainDigits: str, combination :str) :
            if(len(remainDigits)!=0):
                for char in numdict[remainDigits[0]]:
                    combination += char
                    numplace(remainDigits[1:],combination)
                    combination = combination[:-1]

            else:
                ans.append(combination)
        numplace(digits,'')
        return ans