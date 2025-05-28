public class Solution {
    public int[] MaxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        int n = edges1.Length + 1;
        int m = edges2.Length + 1;

        List<int>[] tree1 = BuildTree(n, edges1);
        List<int>[] tree2 = BuildTree(m, edges2);

        // Precompute number of reachable nodes from each node in tree2 within distance (k - 1)
        int maxReachInTree2 = 0;
        for (int i = 0; i < m; i++) {
            int reach = BfsCount(tree2, i, k - 1);
            maxReachInTree2 = Math.Max(maxReachInTree2, reach);
        }

        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            int reach = BfsCount(tree1, i, k);
            result[i] = reach + maxReachInTree2;
        }

        return result;
    }
    private List<int>[] BuildTree(int size, int[][] edges) {
        List<int>[] tree = new List<int>[size];
        for (int i = 0; i < size; i++) {
            tree[i] = new List<int>();
        }
        foreach (var edge in edges) {
            tree[edge[0]].Add(edge[1]);
            tree[edge[1]].Add(edge[0]);
        }
        return tree;
    }

    private int BfsCount(List<int>[] tree, int start, int maxDist) {
        if (maxDist < 0) return 0;

        bool[] visited = new bool[tree.Length];
        Queue<(int node, int dist)> queue = new Queue<(int node, int dist)>();
        visited[start] = true;
        queue.Enqueue((start, 0));

        int count = 0;

        while (queue.Count > 0) {
            var (node, dist) = queue.Dequeue();
            count++;

            if (dist == maxDist) continue;

            foreach (int neighbor in tree[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.Enqueue((neighbor, dist + 1));
                }
            }
        }

        return count;
    }
}