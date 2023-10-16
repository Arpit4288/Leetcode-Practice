class Solution {
public:
    vector<int> getRow(int r) {
        vector<vector<int>> arr(r+1);
        for(int i = 0;i<=r;i++){
            arr[i].resize(i+1);
            arr[i][0] = 1;
            arr[i][i] = 1;
            for(int j = 1;j<i;j++){
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
        return arr[r];
    }
};

