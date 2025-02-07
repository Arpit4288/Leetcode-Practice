public class Solution {
    public int[] QueryResults(int limit, int[][] queries) {
        var ballPair = new Dictionary<int,int>();
        var color = new Dictionary<int,int>();

        int count =0;

        int n = queries.Length;

        var res = new int[n];

        for(int i= 0; i< n ;i++){
            int cont =0;
            if(!color.ContainsKey(queries[i][1])){
                color.Add(queries[i][1], 1);
                count++;
            }else{
                color[queries[i][1]]++;
            }
            if(!ballPair.ContainsKey(queries[i][0])){
                ballPair.Add(queries[i][0],queries[i][1]);
            }else{
                cont = ballPair[queries[i][0]];
                ballPair[queries[i][0]] = queries[i][1]; 
                if(color[cont] >1){
                    color[cont]--;
                }else{
                    color.Remove(cont);
                    count--;
                }
            }
            res[i] = count;
        }

        return res;
         
    }
}