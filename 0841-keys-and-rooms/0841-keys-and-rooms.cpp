class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {        
        vector<bool> visited(rooms.size(), false);
        
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int currVertex = q.front();
            q.pop();
            if(visited[currVertex] == false){
                visited[currVertex] = true;
                for(auto vertex : rooms[currVertex]){
                    if(visited[vertex] == false) q.push(vertex);
                }
            }
        }
        for(auto vertex : visited){
            if(!vertex) return false;
        }
        
        return true;
    }
};