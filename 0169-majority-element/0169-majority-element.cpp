class Solution {
public:
    int majorityElement(vector<int>& arr) {
        if(arr.size() == 1) return arr[0];
        int vote = 1;
        int idx = 0;
        for(int i = 1;i<arr.size();i++){
            if(arr[i] == arr[idx]){
                vote++;
            }
            else{
                vote--;
                if(vote == 0){
                    vote = 1;
                    idx = i;
                }
            }
        }
        return arr[idx];
    }
};