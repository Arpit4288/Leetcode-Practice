class Solution {
public:
    
    int findSubSeqLen(vector<int> &arr, int target){
        int n = arr.size();
        int sum = 0;
        int len = 0;
        for(int i = 0;i<n;i++){
            if(sum + arr[i] <= target){
                sum += arr[i];
                len++;
            }
            else break;
        }
        return len;
    }
    
    
    vector<int> answerQueries(vector<int>& arr, vector<int>& queries) {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for(auto it : queries){
            ans.emplace_back(findSubSeqLen(arr, it));
        }
        return ans;
    }
};