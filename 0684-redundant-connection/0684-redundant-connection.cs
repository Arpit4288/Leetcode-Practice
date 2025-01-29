public class Solution {
    int[] par;
    int[] sz;
    public int Find(int u){

        if(u==par[u]) return u;
        else return par[u]=Find(par[u]);
    }
    public void Join(int u,int v){
        int parU = Find(u);
        int parV = Find(v);
        if(parU!=parV){
            if(sz[parU]>sz[parV]){
                int val = sz[parV];
                sz[parV] = sz[parU];
                sz[parU]=val;
            }
            sz[parV]+=sz[parU];
            par[parU]=parV;
        }
    }
    public bool checkConnect(int u,int v){
        if(Find(u)==Find(v)) return true;
        else return false;
    }
    public int[] FindRedundantConnection(int[][] edges) {
        int n = edges.Length;
        par = new int[n+1];
        sz = new int[n+1];

        for(int i=1;i<=n;i++) {par[i]=i;sz[i]=1;}

        int []ans = new int[2];


        for(int i=0;i<n;i++){
            int a= edges[i][0];
            int b = edges[i][1];
            if(checkConnect(a,b)){
                ans = edges[i];
            }
            else {
                Join(a,b);
            }
        }
        return ans;
        


    }
}