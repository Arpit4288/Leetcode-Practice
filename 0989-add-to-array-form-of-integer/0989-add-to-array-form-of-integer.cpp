class Solution {
public:
    vector<int> addToArrayForm(vector<int>& arr, int k) {
        vector<int> ans;
        int rem = 0;
        int sum = 0;
        for(int i = arr.size()-1;i>=0;i--){
            int add = 0;
            if(k > 0){
                add = k%10;
                k /= 10;
            }
            sum = arr[i] + rem + add;
            if(sum > 9){
                sum = sum%10;
                rem = 1;
            }
            else rem = 0;
            ans.emplace_back(sum);
        }
        while(k > 0){
           int add = k%10 + rem;
            k /= 10;
            if(add > 9){
                add = add%10;
                rem = 1;
            }
            else rem = 0;
            ans.emplace_back(add);
        }
        if(rem > 0) ans.emplace_back(rem);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};