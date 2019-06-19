class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0)
            return 0;
        vector<int> parenStack = {};
        int ans = 0;
        int tmp;
        int length = s.size();
        for(int i=0; i<length; i++)
        {
            if(parenStack.size()!=0 && s[parenStack.back()]=='(' && s[i]==')')
            {
                parenStack.pop_back();
            }
            else
            {
                parenStack.push_back(i);
            }
        }
        if(parenStack.size()!=0)
        {
            for(auto i=parenStack.begin()+1;i<parenStack.end();i++)
            {
                tmp = *i - *(i-1)-1;
                ans = ans>tmp?ans:tmp;
            }
            tmp = (parenStack[0]-0)>(s.size()-parenStack.back())?(parenStack[0]-0):(s.size()-parenStack.back()-1);
        }
        else 
            tmp = s.size();
        ans = ans>tmp?ans:tmp;
        return ans;
    }
};