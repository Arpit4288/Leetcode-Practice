class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intr, vector<int>& newIntr) {
        int n = intr.size();  // total size of the given array intervals
        vector<vector<int>> ans;  // for storing the answer
        int idx = 0;
        while(idx < n && newIntr[0] > intr[idx][1]){  // finding the break point where newInterval overlapping with existing intervals
            ans.emplace_back(intr[idx]);
            idx++;
        }
        // we have founded the break point
        
        while(idx < n && newIntr[1] >= intr[idx][0]){  // merging the newInterval till its ending time is >= starting point of existing interval
            newIntr[0] = min(newIntr[0], intr[idx][0]); // finding the minimum starting point
            newIntr[1] = max(newIntr[1], intr[idx][1]);  // finding the maximum ending point
            idx++;
        }
        ans.emplace_back(newIntr);
        while(idx < n){  // rest of intervals as it is
            ans.emplace_back(intr[idx]);
            idx++;
        }
        return ans;
    }
};