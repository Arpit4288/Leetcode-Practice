public class Solution 
{
    public int FirstCompleteIndex(int[] arr, int[][] mat) 
    {
        int row = mat.Length;
        int col = mat[0].Length;

        Dictionary<int, (int,int)> dict = new  Dictionary<int, (int,int)>();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                dict.Add(mat[i][j], (i,j));
            }
        }

        int[] countR = new int[row];
        int[] countC = new int[col];

        for(int i = 0; i < arr.Length; i ++)
        {
            (int r,int c) = dict[arr[i]];
            countR[r]++;
            countC[c]++;

            if(countR[r] == col || countC[c] == row)
            {
                return i;
            }
        }

        return -1;
    }
}