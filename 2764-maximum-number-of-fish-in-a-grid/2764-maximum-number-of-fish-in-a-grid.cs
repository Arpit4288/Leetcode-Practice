public class Solution {
    public int FindMaxFish(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int maxFish = 0;
        
        bool[,] visited = new bool[m, n];

        // Helper function for DFS
        int DFS(int r, int c) {
            // Boundary and visited check
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0 || visited[r, c])
                return 0;

            visited[r, c] = true;
            int fish = grid[r][c];

            // Explore all four directions
            fish += DFS(r + 1, c);
            fish += DFS(r - 1, c);
            fish += DFS(r, c + 1);
            fish += DFS(r, c - 1);

            return fish;
        }

        // Start DFS from every water cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i, j]) {
                    maxFish = Math.Max(maxFish, DFS(i, j));
                }
            }
        }

        return maxFish;
    }
}