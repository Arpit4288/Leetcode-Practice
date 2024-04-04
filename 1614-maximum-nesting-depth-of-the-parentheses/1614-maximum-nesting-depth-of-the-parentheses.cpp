class Solution {
public:
    int maxDepth(string s) {
        int openCount=0, closeCount=0, maxVal=0, depth=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
                openCount++;
            if(s[i] == ')')
                closeCount++;   
            depth = openCount - closeCount;
            maxVal = max(depth, maxVal);
        }
        return maxVal;
    }
};