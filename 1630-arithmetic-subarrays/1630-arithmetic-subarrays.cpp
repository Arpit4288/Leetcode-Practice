class Solution {
public:
    
    bool isok(vector<int> arr){
        if(arr.size() == 2) return true;
        int diff = arr[1]-arr[0];
        for(int i = 2;i<arr.size();i++){
            if(arr[i]-arr[i-1] != diff) return false;
        }
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<vector<int>> arr;
        for(int i = 0;i<l.size();i++){
            vector<int> temp(nums.begin()+l[i], nums.begin()+r[i] + 1);
            sort(temp.begin(), temp.end());
            arr.emplace_back(temp);
        }
        
//         for(int i = 0;i<arr.size();i++){
//             for(int j = 0;j<arr[i].size();j++) cout<<arr[i][j]<<"  ";
//             cout<<endl;
//         }
        
        
        
        
        vector<bool> ans;
        
        
        for(int i = 0;i<arr.size();i++){
            if(isok(arr[i])) ans.emplace_back(true);
            else ans.emplace_back(false);
        }
        return ans;
    }
};