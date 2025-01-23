public class Solution {
    public int CountServers(int[][] grid) {
        var m = grid.Length;
        var n = grid[0].Length;
        var rc = new int[m];
        var cc = new int[n];

        for(var i=0; i<m; i++) {
            for(var j=0; j<n; j++) {
                rc[i] += grid[i][j];
                cc[j] += grid[i][j];
            }
        }

        var count = 0;
        for(var i=0; i<m; i++) {
            for(var j=0; j<n; j++) {
                if (grid[i][j] == 1 && (rc[i] > 1 || cc[j] > 1))
                    count++;
            }
        }

        return count;
    }
}