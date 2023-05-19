class Solution {
public:
    void dfs(vector<vector<int>>&graph, vector<int>&vis, int node)
    {
        if(vis[node])return;
        
        vis[node]=1;
        for(auto it:graph[node])
        {
            dfs(graph,vis,it);
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        
        vector<int>color(n,-1);//stored color of all the node as -1(initially)
        
        queue<pair<int,int>>q;//node& color of the node
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(graph,vis,i);
                q.push({i,0});//pushed the starting node of each component with color 0
                color[i]=0;//storing the color of node in a vector to be used further
            }
        }
        
        
        while(!q.empty())
        {
            int node=q.front().first;
            int node_color=q.front().second;//color of the current node
            q.pop();
            
            for(auto it:graph[node])
            {
                if(color[it]==-1)//condition when the node has not been visited yet
                {
                    q.push({it,!node_color});//pushed the noode in queue with opposite color
                    color[it]=!node_color;
                }
                
                else if(color[it]==node_color)return false;//founded adjacent nodes with same color
            }
        }
        
        return true;
    }
};