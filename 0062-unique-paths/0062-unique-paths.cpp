class Solution {
public:
    int check(int i , int j, int m, int n, vector<vector<int>> &mem){
        
        if(mem[i][j] != -1) return mem[i][j];
        
        if(i == m-1 || j == n-1) return mem[i][j] = 1;
        return mem[i][j] =  check(i+1, j, m, n, mem) + check(i, j+1, m, n, mem);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return check(0, 0, m, n, mem);
    }
};