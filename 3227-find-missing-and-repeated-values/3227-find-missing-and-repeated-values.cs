public class Solution {
    public int[] FindMissingAndRepeatedValues(int[][] grid) => new int[2]
    {
        grid.SelectMany(m => m).GroupBy(m => m).Where(m => m.Count() > 1).FirstOrDefault().Key,
        Enumerable.Range(1, grid.Length * grid.Length).Except(grid.SelectMany(m => m)).FirstOrDefault()
    };
}