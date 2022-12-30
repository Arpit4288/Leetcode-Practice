class Solution {
public:
    
    void rec(vector<vector<int>> &ans, vector<int> path , int curr, int end, vector<vector<int>>& graph){
        if(curr == end){
            ans.emplace_back(path);
            return;
        }
        for(int i = 0;i<graph[curr].size();i++){
            vector<int> temp = path;
            temp.emplace_back(graph[curr][i]);
            rec(ans, temp, graph[curr][i], end, graph);
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<graph.size();i++){
            mp[i] = graph[i];
        }
        vector<vector<int>> ans;
        vector<int> path;
        path.emplace_back(0);
        rec(ans, path, 0, graph.size()-1, graph);
        return ans;
        
    }
};