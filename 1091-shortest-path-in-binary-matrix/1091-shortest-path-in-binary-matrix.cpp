class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        queue<pair<int,pair<int,int>>>qu;
        vector<vector<int>>visited(m,vector<int>(n,0));
        if(grid[0][0] == 1) return -1;
        qu.push({0,{0,1}});
        int mins = INT_MAX;
        visited[0][0] = 1;
        while(!qu.empty()){
            int r = qu.front().first,c = qu.front().second.first,takentime = qu.front().second.second;
            qu.pop();
            if(r == m-1 && c==n-1){
                mins = min(mins,takentime);
                continue;
            }
            for(int i=-1;i<=1;i++){
                for(int z=-1;z<=1;z++){
                    int row = r+z,col = c+i;
                    if(row == r && col == c) continue;
                    else if(row >=0 && row < m && col >= 0 && col<n && grid[row][col] == 0 && !visited[row][col] ){
                         visited[row][col] =1;
                        qu.push({row,{col,takentime+1}});
                    }
                }
            }
        }
        return mins == INT_MAX?-1:mins;
    }
};