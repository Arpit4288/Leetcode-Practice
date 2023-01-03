class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> counted(strs[0].length(), false);
        int ans = 0;
        for(int i = 1;i<strs.size();i++){
            for(int j = 0;j<counted.size();j++){
                if(!counted[j]){
                    if(strs[i][j] < strs[i-1][j]){
                        ans++;
                        counted[j] = true;
                    }
                }
            }
        }
        return ans;
    }
};