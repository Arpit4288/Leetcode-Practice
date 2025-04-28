public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
         if (matrix == null || matrix.Length == 0 || matrix[0].Length == 0) return false;
        int i = matrix.Length - 1;
        int j = matrix[0].Length - 1;
        if (target > matrix[i][j] || target < matrix[0][0]) return false;

        int x = 0;
        int y = j;
        while (x <= i && y >= 0)
        {
            if (target == matrix[x][y]) return true;
            else if (target < matrix[x][y])
            {
                y--;
            }
            else
            {
                x++;
            }
        }
        return false;
    }
}