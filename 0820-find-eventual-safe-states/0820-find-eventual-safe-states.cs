public class Solution {
    public IList<int> EventualSafeNodes(int[][] g) {
        int n = g.Length;
        IList<int> ans = new List<int>();
        int[] isTerminal = new int[n];
        bool[] visited = new bool[n];
        for(int i=0;i<n;i++)    // O(n)
            if(g[i].Length==0)
            // 2 = Terminal, 1 = Not Terminal, 0 = not evaluated yet
                isTerminal[i]=2;
        
        for(int i=0;i<n;i++)
            if(DFS(i))  // if terminal or all path lead to terminal add to result
                ans.Add(i);

        return ans;

        // local helper func
        bool DFS(int idx)
        {   
            if(visited[idx]) return false;
            // if solved before, return true if terminal else false
            if(isTerminal[idx]!=0) return isTerminal[idx]==2;
            
            bool terminalNode = true;
            visited[idx]=true;  // mark visited

            foreach(var adj in g[idx])
                terminalNode &= DFS(adj);
            
            visited[idx]=false; // mark unvisited
            isTerminal[idx] = (terminalNode ? 2 : 1);
            return terminalNode;
        }
    }
}