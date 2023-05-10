class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int> (n));
        int rs = 0, re = n-1, cols = 0, cole = n-1;
        int val = 0;
        while(rs <= re && cols <= cole){
            for(int i = cols;i<=cole;i++){
                arr[rs][i] = ++val;
            }
            rs++;
            for(int i = rs;i<=re;i++){
                arr[i][cole] = ++val;
            }
            cole--;
            for(int i = cole;i>=cols;i--){
                arr[re][i] = ++val;
            }
            re--;
            for(int i = re;i>=rs;i--){
                arr[i][cols] = ++val;
            }
            cols++;
        }
        return arr;
        
    }
};