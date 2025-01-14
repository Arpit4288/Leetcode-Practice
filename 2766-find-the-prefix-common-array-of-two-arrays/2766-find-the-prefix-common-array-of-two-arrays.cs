public class Solution
{
  public int[] FindThePrefixCommonArray(int[] a, int[] b)
  {
    var n = a.Length;
    var result = new int[n];
    ulong ma = 0, mb = 0;
    for (var i = 0; i < n; i++)
    {
      ma |= 1ul << a[i];
      mb |= 1ul << b[i];
      result[i] = BitOperations.PopCount(ma & mb);
    }
    return result;
  }
}