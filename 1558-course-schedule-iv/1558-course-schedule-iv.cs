public class Solution {
    public IList<bool> CheckIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        bool[][] isConnected = new bool[numCourses][];
        for (int i = 0; i < numCourses; ++i) {
            isConnected[i] = new bool[numCourses];
        }

        for (int i = 0; i < prerequisites.Length; ++i) {
            var (u, v) = (prerequisites[i][0], prerequisites[i][1]);
            isConnected[u][v] = true;
        }

        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {                
                    if (isConnected[i][k] && isConnected[k][j]) {
                        isConnected[i][j] = true;
                    }
                }
            }
        }

        List<bool> result = new List<bool>();
        for (int i = 0; i < queries.Length; ++i) {
            var (u, v) = (queries[i][0], queries[i][1]);
            result.Add(isConnected[u][v]);
        }

        return result;
    }
}