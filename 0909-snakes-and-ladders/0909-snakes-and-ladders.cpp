class Solution {
public:
    pair<int,int> findLocation(int currNum, int n){ // function for locating the row and col by giving the number on board
        pair<int,int> ans;  // fist is row and second is for col
        int row = n - (currNum - 1) / n  -1;
        int col;
        col = (currNum-1)%n;
        if (row % 2 == n % 2) {
            ans.first = row;
            ans.second = n-1-col;
        }
        else {
            ans.first = row;
            ans.second = col;
        }
        return ans;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;
        queue<int> q; // DFS queue
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // visited boxes
        visited[n-1][0] = true;
        if(board[n-1][0] == -1) q.push(1);
        else q.push(board[n-1][0]); 
        
        // DFS
        while(!q.empty()){
            int len = q.size();
            for(int i = 0;i<len;i++){
                int currPos = q.front();
                q.pop();
                if(currPos == n*n) return steps;
                for(int k = 1;k<=6;k++){
                    if(k + currPos > n*n ) break;
                    pair<int,int> loc = findLocation(k + currPos, n);
                    int row = loc.first;
                    int col = loc.second;
                    if(visited[row][col]) continue;
                    visited[row][col] = true;
                    if(board[row][col] == -1) q.push(k + currPos);
                    else q.push(board[row][col]);
                }
            }
            steps++;
        }
        return -1;
        
    }
};