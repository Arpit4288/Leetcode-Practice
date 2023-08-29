class Solution {
public:
    
    void solve(string customer, vector<int> &arr, int &flag, int &maxi, int &ans){
        int n = customer.size();
        for(int i = 1; i<n; i++)
        {
            flag = (customer[i] == 'Y');
            arr[i] = arr[i-1] + flag;
            int temp = 2 * arr[i] - i - 1;

            if(temp > maxi)
            {
                maxi = temp;
                ans = i+1;
            }
        }
    }
    
    int bestClosingTime(string customer) {

        int flag = (customer[0] == 'Y');
        int maxi = flag;
        int ans = flag;

        vector<int> arr(customer.size());
        arr[0] = flag;        
        solve(customer,arr, flag, maxi, ans);
        return ans;
    }
};