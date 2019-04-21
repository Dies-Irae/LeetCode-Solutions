class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        rangeList = list(range(1, n+1))
        def doCombine(numList : List, tmpList : List, remainDeepth : int):
            #print(numList, tmpList)
            if(remainDeepth == 1):
                for num in numList:
                    ans.append(tmpList+[num])
                return
            else:
                for num in numList:
                    doCombine(numList[numList.index(num)+1:], tmpList+[num], remainDeepth-1)

        doCombine(rangeList, [], k)
        return ans
                    
            