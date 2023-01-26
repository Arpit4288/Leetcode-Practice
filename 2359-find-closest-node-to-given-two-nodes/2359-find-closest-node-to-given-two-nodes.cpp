class Solution {
public:
    
    void dfs(int currNode, vector<int> &edges, vector<int> &dis_node, vector<bool> &visited, int currDist){
        if(currNode != -1 && !visited[currNode]){  // dfs will call if node is node -1 as well as it have to connect to the next if not then dfs ends
            visited[currNode] = true;
            dis_node[currNode] = currDist;
            return dfs(edges[currNode], edges, dis_node, visited, currDist + 1);
        }
        return;
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dis_node1(edges.size(), -1);  // all distances from node1
        vector<int> dis_node2(edges.size(), -1);  // // all distances from node2
        vector<bool> visited(edges.size(), false);  // wheather the node is visited or not
        
        dfs(node1, edges, dis_node1, visited, 0);  // dfs call for node1
        visited.assign(edges.size(), false);  // reassign visited array to all false
        dfs(node2, edges, dis_node2, visited, 0); //  dfs call for node2
        
        int mini_dis = INT_MAX;  // assigning the min distance as INT_MAX
        int ans_node = -1;    // assigning the ans node as -1 if none is ans we have to return ans as -1
        for(int i = 0;i<edges.size();i++){  // loop through the distance array
            if(dis_node1[i] != -1 && dis_node2[i] != -1){  // the distance from node1, node2 to i is not -1 then we can consider for the ans
                if(mini_dis > max(dis_node1[i], dis_node2[i])){  // if we find less disstance than previous then we can change our ans_node
                    mini_dis = max(dis_node1[i], dis_node2[i]);
                    ans_node = i;
                }
            }
        }
        return ans_node;
        
    }
};