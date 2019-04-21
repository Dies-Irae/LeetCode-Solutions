class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
       # print(strs)
        length = len(strs)
        clip = length //2
        i = 0
        if(length == 0):
            return ''
        elif(length == 1):
            return strs[0]
        elif(length == 2):
            while(i <len(strs[0]) and i < len(strs[1]) and strs[0][i] == strs[1][i]):
                i += 1  
            return strs[0][0:i]
        else:
            return self.longestCommonPrefix([self.longestCommonPrefix(strs[0:clip]),self.longestCommonPrefix(strs[clip:])])
            
        
        
        