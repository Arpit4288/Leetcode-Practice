public class Solution {
    public string SmallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf = new(26);
        for (int i = 0; i < s1.Length; i++){
            uf.Union(s1[i]-'a', s2[i]-'a');
        }
        StringBuilder sb = new();
        for (int i = 0; i < baseStr.Length; i++){
            sb.Append((char)('a'+uf.Find(baseStr[i]-'a')));
        }
        return sb.ToString();
    }

    public class UnionFind {
        public int[] root { get; set; }
        public int[] rank { get; set; }

        public UnionFind(int n){
            root = new int[n];
            rank = new int[n];
            for (int i = 0 ; i < n; i++){
                root[i] = i;
                rank[i] = 26-i;
            }
        }

        public int Find(int x){
            if (root[x] == x) return x;
            else return Find(root[x]);
        }

        public void Union(int x, int y){
            int rootx = Find(x);
            int rooty = Find(y);

            if (rootx == rooty) return;

            if (rank[rootx] > rank[rooty]){
                root[rooty] = rootx;
            }
            else {
                root[rootx] = rooty;
            }
        }
    }
}