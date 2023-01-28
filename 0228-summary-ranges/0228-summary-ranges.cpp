class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        int n = arr.size();
        vector<string> ans;
        if(n == 0) return ans;
        int st = arr[0], end = arr[0];
        for(int i = 1;i<n;i++){
            if(arr[i] == arr[i-1]+1){
                end = arr[i];
            }
            else{
                if(st == end){
                    string temp = to_string(st);
                    ans.emplace_back(temp);
                    
                }
                else{
                    string first = to_string(st);
                    string sec = to_string(end);
                    string temp = first + "->" + sec;
                    ans.emplace_back(temp);
                }
                st = arr[i];
                end = arr[i];
            }
        }
        
        if (st == end){
            string temp = to_string(st);
            ans.emplace_back(temp);
        }
        else{
            string first = to_string(st);
            string sec = to_string(end);
            string temp = first + "->" + sec;
            ans.emplace_back(temp);
        }
        return ans;
    }
};