class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                arr.emplace_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                arr.emplace_back(nums2[j]);
                j++;
            }
            else{
                arr.emplace_back(nums1[i]);
                arr.emplace_back(nums2[j]);
                i++;
                j++;
            }
        }
        while(i < m) arr.emplace_back(nums1[i++]);
        while(j < n) arr.emplace_back(nums2[j++]);
        for(i = 0;i<m + n;i++) nums1[i] = arr[i];
    }
};