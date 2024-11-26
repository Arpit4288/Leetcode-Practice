public class Solution {
    public int FindChampion(int n, int[][] edges) {

         bool [] cham= new bool[n];
    Array.Fill(cham,true);
    for (int i=0; i< edges.Length; i++){
       cham[ edges[i][1]]=false;
    } 
    int ans=-1;
    for(int i=0; i<cham.Length; i++){
        if (cham[i]) {if(ans==-1)ans=i;
        else return -1;}
    }
    return ans;;
    }
}