class Solution {
public:

    
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
         int l = arr.size();
        vector<int> h(l);
        int ans = 0;
       int mod =  pow(10,9)+7;
        for(int i=l-1; i>=0; i--){
            while(!s.empty() && arr[i]<=arr[s.top()]){
                s.pop();
            }
         h[i] = s.empty()?-1:s.top();
        s.push(i);
            
        }
   
        for(int i=l-1; i>=0; i--){
            if(h[i] == -1){ // if -1 then easy maths
                arr[i] =  (l-i)*arr[i];
                
            }
            else{ // if not then we already have sum till h[i] next smaller element(as //this gonna repeat we added it) as from behind we are traversing. So only have //to add it to the remaining subarrays between.
// take an example to understand better.
                arr[i] = arr[h[i]]+arr[i]*(h[i]-i);
            }
            ans += arr[i];
            ans = ans%mod;
        }
        return ans%mod;
    }
};