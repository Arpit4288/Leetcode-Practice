class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        st.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        vector<int> arr(st.begin(), st.end()); // taking all the numbers in arr (st contains elements in non-decreasing order)
        int st = arr[0], end = arr[0];  // initially start and end is first element
        for(int i = 1;i<arr.size();i++){
            if(arr[i] == arr[i-1]+1){ // if current element is just greater than previous then it means it not breaking the range letsc continue with range
                end = arr[i];
            }
            else{ // if current element is not just greater than previous then it means it breaking the range
                vector<int> temp;
                temp.emplace_back(st);
                temp.emplace_back(end);
                ans.emplace_back(temp);
                st = arr[i];
                end = arr[i];
            }
        }
        vector<int> temp;
        temp.emplace_back(st);
        temp.emplace_back(end);
        ans.emplace_back(temp);
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */