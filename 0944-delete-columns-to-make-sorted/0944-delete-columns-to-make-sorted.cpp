class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<bool> counted(strs[0].length(), false); // for verifying whether we have finished with particular column or not
        int ans = 0;
        for(int i = 1;i<strs.size();i++){
            for(int j = 0;j<counted.size();j++){ // for every column in string
                if(!counted[j]){ // if it not finished then we have to check either it follows the rule or not
                    if(strs[i][j] < strs[i-1][j]){
                        ans++; // if it break the rule then we have to break it
                        counted[j] = true; // make that column finished
                    }
                }
            }
        }
        return ans;
    }
};