class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for(auto it : nums1) set1.insert(it);
        for(auto it : nums2) set2.insert(it);
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_set<int> ansSet;
        
        for(int i = 0;i<nums1.size();i++){
            if(set2.find(nums1[i]) == set2.end()){
                ansSet.insert(nums1[i]);
            }
        }
        for(auto it : ansSet) temp.emplace_back(it);
        ans.emplace_back(temp);
        ansSet.clear();
        temp.clear();
        for(int i = 0;i<nums2.size();i++){
            if(set1.find(nums2[i]) == set1.end()){
                ansSet.insert(nums2[i]);
            }
        }
        for(auto it : ansSet) temp.emplace_back(it);
        ans.emplace_back(temp);
        return ans;
    }
};