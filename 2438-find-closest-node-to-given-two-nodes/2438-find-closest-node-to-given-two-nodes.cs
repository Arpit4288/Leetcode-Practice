public class Solution {
    // Distance finder for a node with other nodes
    void DFSTravel(int currentNode, int[] lst, List<int> disMap, HashSet<int> st, int dis){
        st.Add(currentNode);
        disMap[currentNode] = dis;
        if(!st.Contains(lst[currentNode]) && lst[currentNode] != -1){
            DFSTravel(lst[currentNode],lst,disMap,st,dis+1);
        }
    }
    public int ClosestMeetingNode(int[] edges, int node1, int node2) {
        List<int> disMap1 = new();
        List<int> disMap2 = new();

        for(int i = 0;i<edges.Length;i++){
            disMap1.Add(-1);
            disMap2.Add(-1);
        }
        DFSTravel(node1,edges,disMap1,new HashSet<int>(),0);
        DFSTravel(node2,edges,disMap2,new HashSet<int>(),0);


        int answer = -1; // answer node
        int currentMin = int.MaxValue;
            Console.WriteLine(currentMin);

        for(int i = 0;i<edges.Length;i++){
            if(disMap1[i] == -1 || disMap2[i] == -1) continue;

            int max = disMap1[i] >= disMap2[i] ? disMap1[i]:disMap2[i];
            Console.WriteLine(max);
            if(currentMin > max ){
                answer = i;
                currentMin = max;
            }
        }

        return answer;
        
    }
}