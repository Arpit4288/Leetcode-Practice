class Solution {
public:
    
    bool isEmpty(unordered_map<int,int> & mp){
        for(auto it : mp){
            if(it.second > 0) return false;
        }
        return true;
    }
    
    vector<vector<int>> findMatrix(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++) mp[arr[i]]++;
        
//         for(auto it : mp){
//             cout<<it.first<<" : "<<it.second<<" , ";
//         }
        
        vector<vector<int>> ans;
        while(!isEmpty(mp)){
            vector<int> temp;
            for(auto it : mp){
                if(it.second > 0){
                    temp.emplace_back(it.first);
                    mp[it.first]--;
                }
            }
            ans.emplace_back(temp);
        }
        // cout<<endl;
        return ans;
    }
};