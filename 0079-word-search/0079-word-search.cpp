class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool backtrack(int depth, int i, int j, vector<vector<bool>>& visit, vector<vector<char>>& board, string& word, int xsize, int ysize){
        if(word[depth] != board[i][j]){
            return false;
        }
        if(depth == word.length() - 1){
            return true;
        }
        visit[i][j] = true;
        for(int p = 0;p < 4; ++p){
            int newi = i + dx[p];
            int newj = j + dy[p];
            if(newi >= 0 && newi < xsize && newj >=0 && newj < ysize && !visit[newi][newj]){
                if(backtrack(depth + 1, newi, newj, visit, board, word, xsize, ysize)){
                    return true;
                }
            }
        }
        visit[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == ""){
            return true;
        }
        int xsize = board.size();
        if(xsize == 0){
            return false;
        }
        int ysize = board[0].size();
        vector<vector<bool>> visit =  vector<vector<bool>>(xsize, vector<bool>(ysize, false));
        for(int i = 0;i < xsize; ++i){
            for(int j = 0;j < ysize; ++j){
                visit[i][j] = true;
                if(backtrack(0, i, j, visit, board, word, xsize, ysize)){
                    return true;
                }
                visit[i][j] = false;
            }
        }
        return false;
    }
};