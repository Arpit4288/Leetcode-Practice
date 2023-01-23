class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0){ // edge cases
            if(n == 1) return 1;
            else return -1;
        }
        vector<pair<int,int>> arr(n+1, pair<int,int>({0,0}));  // first value in pair is for how many people he trusts, and second value is for how many trust this people
        // for(int i = 0;i<=n;i++) cout<<arr[i].first<<" "<<arr[i].second<<" ,, ";
        for(auto it : trust){
            arr[it[0]].first++;
            arr[it[1]].second++;
        }
        
        // after filling all details we easily find if there is person who trusts no one and also trusted by all of them expem himself/herself.
        for(int i = 1;i<=n;i++){
            if(arr[i].first == 0){ // the person trusts no one
                if(arr[i].second == n-1) return i; // if it trusted by all other persons then it it our ans
            }
        }
        return -1; // at last if not find the jude
        
    }
};