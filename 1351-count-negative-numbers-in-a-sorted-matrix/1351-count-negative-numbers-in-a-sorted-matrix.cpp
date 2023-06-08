class Solution {
public:
    int countNegatives(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        int row = m-1, col = 0;
        int ans = 0;
        while(row >= 0 && col < n){
            if(arr[row][col] < 0){
                ans += (n-col);
                row--;
            }
            else col++;
        }
        return ans;
    }
};