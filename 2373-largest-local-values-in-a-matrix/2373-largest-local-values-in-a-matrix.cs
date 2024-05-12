/*

public class Solution {
    public int[][] LargestLocal(int[][] grid) {
        int [][] result = new int[grid.Length-2][];
        for (int i = 0; i < grid.Length-2; i++)
            result[i] = new int[grid.Length-2];
        for (int i = 1; i < grid.Length - 1; i++) {
            for (int j = 1; j < grid.Length -1; j++)    
                result[i-1][j-1] = FindLargest(grid, i, j);
        }
        return result;
    }
    public int FindLargest(int[][] matrix, int x, int y) {
        int max = 0;
        for (int i = x-1; i <= x + 1; i++) 
            for (int j = y-1; j <= y + 1; j++)
                max = Math.Max(max, matrix[i][j]);        
        return max;
    }
}

*/

public class Solution {
    public int[][] LargestLocal(int[][] grid) {
        int [][] result = new int [grid.Length-2][];
        for(int i = 0; i<grid.Length-2; i++){
            result[i] = new int[grid.Length-2];
        }
        for(int i = 1; i<grid.Length - 1; i++){
            for(int j = 1; j<grid.Length-1; j++){
                result[i-1][j-1] = FindLargest(grid, i, j);
            }
        }
        return result;
    }
    
    public int FindLargest(int[][] matrix, int x, int y){
        int max = 0;
        for(int i = x-1; i<= x+1; i++){
            for(int j = y-1; j<= y+1; j++){
                max = Math.Max(max, matrix[i][j]);
            }
        }
        return max;
    }
}