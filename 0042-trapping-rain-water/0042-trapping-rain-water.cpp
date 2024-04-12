class Solution {
public:
    int trap(vector<int>& arr) {
        vector<long long> left(arr.size());
        left[0] = arr[0];
        int maxi = arr[0];
        for(int i = 1;i<arr.size();i++){
            maxi = max(maxi, arr[i]);
            left[i] = maxi;
        }
        // for(int i = 0;i<arr.size();i++) cout<<left[i]<<"  ";
        cout<<endl;
        vector<long long> right(arr.size());
        right[arr.size()-1] = arr[arr.size()-1];
        maxi = arr[arr.size()-1];
        for(int i = arr.size()-2;i>=0;i--){
            maxi = max(maxi, arr[i]);
            right[i] = maxi;
        }
        // for(int i = 0;i<arr.size();i++) cout<<right[i]<<"  ";
        
        
        int ans = 0;
        for(int i = 0;i<arr.size();i++){
            left[i] = min(left[i], right[i]);
            ans += left[i]-arr[i];
        }
        
        return ans;
    }
};