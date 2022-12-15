class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int text1size=text1.size();
        int text2size=text2.size();

        vector<int> prev(text2size+1)  , cur((text2size+1));

        for(int i=0;i<=text2size;i++)prev[i]=0;
        
        for(int i=1;i<=text1size;i++){
            prev[0]=0;
            for(int j=1;j<=text2size;j++){
                if(text1[i-1]==text2[j-1])
                    cur[j]=1+prev[j-1];
                else 
                    cur[j]=max(prev[j] , cur[j-1]);
            }
            prev=cur;
        }
        return prev[text2size];
    }
};