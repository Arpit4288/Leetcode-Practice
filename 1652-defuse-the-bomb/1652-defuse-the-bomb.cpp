class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k==0) return vector<int>(n);

        vector<int> pre(n),res(n);
        bool f = false;

        if(k < 0){
            reverse(code.begin(),code.end());
            k = -1 * k;
            f = true;
        }

        pre[0] = code[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + code[i];
        }

        for(int i=0; i<n; i++){
            if(i+k < n){
                res[i] = pre[i+k]-pre[i];
            }else{
                res[i] = (pre[n-1] - pre[i]) + pre[(i+k)%n];
            }
        }

        if(f == true){
            reverse(res.begin(),res.end());
        }
        
        return res;
    }
};