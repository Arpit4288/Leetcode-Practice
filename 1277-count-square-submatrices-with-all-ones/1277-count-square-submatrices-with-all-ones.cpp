class Solution {
public:

    int getMatSum(int i, int j, int x, int y, vector<vector<int>> &matrix){
        int one = ((j-1 >= 0) ? matrix[x][j-1] : 0);
        int two = ((i-1 >= 0) ? matrix[i-1][y] : 0);
        int three = ((i-1 >= 0 && j-1 >= 0) ? matrix[i-1][j-1] : 0);
        int ar = (matrix[x][y] - one - two + three);
        return ar;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        
        // Create the 2D prefix array
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] += matrix[i-1][j];
            }
        }

        // Query from this prefix array for all possible square matrix
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = i, y = j;
                while(x < m && y < n && getMatSum(i,j,x,y,matrix) == ((x-i+1)*(y-j+1))){
                    x++;
                    y++;
                    res++;
                }
            }
        }
        return res;
    }
};