class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i = 0;i<n;i++){
            if(n%2 != 0 && i == floor(n/2.0)){
                ans += mat[i][i];
                continue;
            }
            ans += mat[i][i];
            ans += mat[i][n-i-1];
        }
        return ans;
    }
};