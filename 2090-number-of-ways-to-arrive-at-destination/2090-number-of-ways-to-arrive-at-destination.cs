public class Solution
{
    public int CountPaths(int n, int[][] roads)
    {
        var graph = new Dictionary<int, List<(int, int)>>();
        foreach (var road in roads)
        {
            if (!graph.ContainsKey(road[0]))
                graph[road[0]] = [];

            if (!graph.ContainsKey(road[1]))
                graph[road[1]] = [];

            graph[road[0]].Add((road[1], road[2]));
            graph[road[1]].Add((road[0], road[2]));
        }

        return Dijkshtra.CountShortestPath(n, graph);
    }

    public class Dijkshtra
    {
        public static int CountShortestPath(int n, Dictionary<int, List<(int, int)>> graph)
        {
            var dist = new long[n];
            var ways = new long[n];
            var visited = new bool[n];
            var pq = new PriorityQueue<int, long>();

            Array.Fill(dist, long.MaxValue);

            dist[0] = 0;
            ways[0] = 1;
            pq.Enqueue(0, 0);

            while (pq.Count > 0)
            {
                var node = pq.Dequeue();
                if(visited[node])
                    continue;

                visited[node] = true;
                if(graph.ContainsKey(node))
                {
                    foreach (var vertex in graph[node])
                    {
                        var temp = dist[node] + vertex.Item2;
                        if (temp == dist[vertex.Item1])
                        {
                            ways[vertex.Item1] = (ways[vertex.Item1] + ways[node]) % 1000000007;
                        }
                        else if (temp < dist[vertex.Item1])
                        {
                            dist[vertex.Item1] = temp;
                            ways[vertex.Item1] = ways[node];
                            pq.Enqueue(vertex.Item1, temp);
                        }
                    }
                }
            }

            return (int)ways[n - 1];
        }
    }
}