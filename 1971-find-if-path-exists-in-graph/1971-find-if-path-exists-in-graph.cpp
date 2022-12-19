class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> edgeMap;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            edgeMap[u].emplace_back(v);
            edgeMap[v].emplace_back(u);           
        }
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int currEdge = q.front();
            q.pop();
            vector<int> connectedEdges = edgeMap[currEdge];
            for(auto edge : connectedEdges){
                if(!visited[edge]){
                    visited[edge] = true;
                    q.push(edge);
                }
            }
            if(visited[end]) return true;
        }
        return false;
    }
};