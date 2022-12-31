class Solution {
public:
    
    int dfs(vector<vector<int>> grid, int row, int col, int zeros){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == -1){
            return 0;
        }
        if(grid[row][col] == 2) return zeros == -1 ? 1 : 0;
        grid[row][col] = -1;  // mark visited
        zeros--; // down one zero
        int totalPaths = dfs(grid, row+1, col, zeros) + 
            dfs(grid, row, col+1, zeros) + 
            dfs(grid, row-1, col, zeros) + 
            dfs(grid, row, col-1, zeros);
        grid[row][col] = 0; // backtrack
        zeros++;
        return totalPaths;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zeros = 0, row = 0, col = 0;
        for(int r = 0;r<grid.size();r++){
            for(int c = 0; c < grid[0].size();c++){
                if(grid[r][c] == 0) zeros++;
                if(grid[r][c] == 1){
                    row = r; col = c; // where to start
                }
            }
        }
        
        return dfs(grid, row, col, zeros);
    }
};