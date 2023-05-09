class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int rs = 0, re = arr.size()-1, cs = 0, ce = arr[0].size()-1;
        while(rs <= re && cs <= ce){
            for(int i = cs;i<=ce;i++){
                ans.emplace_back(arr[rs][i]);
            }
            rs++;
            for(int i = rs;i<=re;i++){
                ans.emplace_back(arr[i][ce]);
            }
            ce--;
            if(cs > ce || rs > re) break;
            for(int i = ce;i>= cs;i--){
                ans.emplace_back(arr[re][i]);
            }
            re--;
            for(int i = re;i>=rs;i--){
                ans.emplace_back(arr[i][cs]);
            }
            cs++;
        }
        return ans;
    }
};