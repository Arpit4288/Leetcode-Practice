class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;  // storing all dislikes persons
        for(auto dislike : dislikes){
            graph[dislike[0]].emplace_back(dislike[1]);
            graph[dislike[1]].emplace_back(dislike[0]);
        }
        
        vector<int> color(n+1, -1); // coling two group with 0 / 1 , initiallly all are -1
        for(int i = 1;i<=n;i++){
            if(color[i] == -1){
                queue<int> q;  // BFS
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(auto neighbour : graph[curr]){ // calling those persons who are not liked by the current person
                        if(color[neighbour] == color[curr]) return false;  // if current person and person who are disliked are in the same group then return false
                        if(color[neighbour] == -1){
                            color[neighbour] = color[curr] == 1 ? 0 : 1;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }
        return true;
    }
};