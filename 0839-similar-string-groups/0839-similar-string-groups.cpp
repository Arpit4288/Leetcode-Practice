class DisjointSet {
public: 
    vector<int> parent, size; 
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
public:
    bool isSimilar(string &a,string &b){
        int n=a.size();
        int countMatchingLetters=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                countMatchingLetters++;
            }
        }
        return countMatchingLetters==n or countMatchingLetters==n-2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j]))
                    ds.unionBySize(i,j);
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                res++;
            }
        }
        return res;
    }
};
