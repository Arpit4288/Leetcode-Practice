public class Solution {
    public long PutMarbles(int[] weights, int k) {
          int n = weights.Length;
  int[] pairWeights = new int[n - 1];

  for (int i = 1; i < n; i++)
      pairWeights[i - 1] = weights[i] + weights[i - 1];

  Array.Sort(pairWeights);

  long maxScore = weights[0] + weights[n - 1];
  long minScore = weights[0] + weights[n - 1];

  for (int i = n - k; i < n - 1; i++)
      maxScore += pairWeights[i];

  for (int i = 0; i < k - 1; i++)
      minScore += pairWeights[i];

  return maxScore - minScore;
    }
}