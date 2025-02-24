public class Solution {
    private class Node {
        public int distFromBob=int.MaxValue;
        public int pathForBob=int.MaxValue;
        public readonly List<int> neighbors=new();
    }

    public int MostProfitablePath(int[][] edges, int bob, int[] amount) {
        // build initial array of nodes
        Node[] nodes=new Node[amount.Length];
        for(int ni=0; ni<amount.Length; ni++) {
            nodes[ni]=new Node();
        }
        // connect the nodes
        foreach(var e in edges) {
            int ni1=e[0], ni2=e[1];
            nodes[ni1].neighbors.Add(ni2);
            nodes[ni2].neighbors.Add(ni1);
        }
        // BFS from Bob outward to record distance
        List<int> curr=new() { bob }, next=new();
        int distFromBob=0;
        bool[] visited=new bool[nodes.Length];
        bool found0=false;
        while(!found0 && curr.Count>0) {
            foreach(var ci in curr) {
                visited[ci]=true;
                Node node=nodes[ci];
                node.distFromBob=distFromBob;
                if(ci==0) {
                    found0=true;
                    break;
                }
                foreach(var ni in node.neighbors) {
                    if(!visited[ni]) {
                        next.Add(ni);
                    }
                }
            }
            curr.Clear();
            (curr, next)=(next, curr);
            distFromBob++;
        }
        // Retrace Bob's path to 0
        for(int ni=0; ;) {
            Node node=nodes[ni];
            node.pathForBob=node.distFromBob;
            if(ni==bob) {
                break;
            }
            int nextDist=node.distFromBob-1;
            foreach(var nni in node.neighbors) {
                if(nodes[nni].distFromBob==nextDist) {
                    ni=nni;
                    break;
                }
            }
        }
        Array.Clear(visited);
        visited[0]=true;
        // recursively find best path for Alice starting from node 0
        return BestPath(0, 0);

        int BestPath(int ni, int distFrom0) {
            Node node=nodes[ni];
            int sum=amount[ni], pathForBob=node.pathForBob;
            // adjust amount if Bob's been here already
            if(distFrom0==pathForBob) sum>>=1;
            if(distFrom0>pathForBob) sum=0;
            distFrom0++;
            // Recursively find the best path going down unvisited neighbors
            int best=int.MinValue, bestNode=-1;
            foreach(var nni in node.neighbors) {
                if(!visited[nni]) {
                    visited[nni]=true;
                    int s=BestPath(nni, distFrom0);
                    if(s>best) {
                        best=s;
                        bestNode=nni;
                    }
                    visited[nni]=false;
                }
            }
            // adjust sum if we found a unvisited neighbor
            if(bestNode>=0) {
                sum+=best;
                visited[bestNode]=true;
            }
            return sum;
        }
    }
}