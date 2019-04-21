class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0 :
            return 0
        maxlen = 1
        head = 0
        while head < len(s):
            rear = head + maxlen
            charset = set(s[head:rear])
            if(len(charset)<len(s[head:rear])):
                head += 1
                continue
            while rear < len(s):
                if s[rear] in charset:
                    break
                else:
                    charset.add(s[rear])
                    maxlen = (len(charset) if(len(charset)>maxlen) else maxlen)
                rear += 1
            head += 1
        return maxlen

                
                
        