// class Solution {
// public:
//     vector<int> findArray(vector<int>& arr) {
//         // int cnt = 5^7;
//         // cout<<cnt<<" ";
//         int n = arr.size();
//         vector<int> ans;
//         int pre = arr[0];
//         int temp = arr[0];
//         ans.emplace_back(arr[0]);
//         cout<<temp<<" "<<arr[0]<<endl;
//         for(int i = 1;i<n;i++){
//             cout<<temp<<" "<<arr[i]<<" "<<(temp^arr[i])<<endl;
//             pre
//             temp = (temp^pre);
//             ans.emplace_back(temp);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        int N=arr.size();
        vector<int> out(N,0);
        out[0]=arr[0];
        for(int i=0;i<N-1;i++){
            out[i+1] = arr[i]^arr[i+1];
        }
        return out;

    }
};