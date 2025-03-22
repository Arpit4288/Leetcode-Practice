public class Solution
{
    public int CountCompleteComponents(int n, int[][] edges)
    {
        var adj = new List<int>[n];
        Span<long> scores = stackalloc long[n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = [];
            scores[i] = 1L << i;
        }
        foreach(int[] e in edges)
        {
            adj[e[0]].Add(e[1]);
            adj[e[1]].Add(e[0]);
            scores[e[0]] += 1L << e[1];
            scores[e[1]] += 1L << e[0];
        }
        int result = 0;
        Span<bool> visited = stackalloc bool[n];
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            bool complete = true;
            foreach(int j in adj[i])
            {
                visited[j] = true;
                complete = complete && scores[i] == scores[j];
            }
            if (complete)
            {
                result++;
            }
        }
        return result;
    }
}