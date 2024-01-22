class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        /* Initializing ans vector */
        vector<int> ans;
        
        /* Initializing count vector for storing count of every element and index should be an element itself */
        vector<int> count(arr.size()+1,0);
        /* eg. [1,2,2,4] ---> count[4+1] = {INT_MIN, 1, 2, 0, 1} means 1 occurs 1 time, 2 occurs 2 times, 3 occurs 0 time and 4 ocurrs 1 time  */
        
        /* 0th index no of use */
        count[0] = INT_MIN;
        
        /* filling the count array */
        for(int i = 0;i<arr.size();i++) count[arr[i]]++;
        
        /* miss--> missing number,  dupl--> duplicate number */
        int miss, dupl;
        
        // Iterating through count array to find ans
        for(int i = 1;i<count.size();i++){
            if(count[i] == 0) miss = i;
            if(count[i] == 2) dupl = i;
        }
        ans.emplace_back(dupl);
        ans.emplace_back(miss);
        return ans;
    }
};