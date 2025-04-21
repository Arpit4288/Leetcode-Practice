public class Solution
{
    public int NumberOfArrays(int[] differences, int lower, int upper)
    {
        long min = 0, max = 0, current = 0;
        for (int i = 0; i < differences.Length; i++)
        {
            current += differences[i];
            min = Math.Min(min, current);
            max = Math.Max(max, current);
        }
        return (int)Math.Max(0, upper - lower - (max - min) + 1);
    }
}