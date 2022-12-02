class Solution {
public:
    bool closeStrings(string s1, string s2) {
        unordered_map<int,int> mp;
        for(auto it : s1) mp[it]++;
        unordered_map<int,int> mp2;
        for(auto it : s2) mp2[it]++;

        for(auto it : mp){
            if(mp2.find(it.first) == mp2.end()) return false;
        }


        unordered_map<int,int> st1;
        unordered_map<int,int> st2;
        for(auto it : mp) st1[it.second]++;
        for(auto it : mp2) st2[it.second]++;
        // for(auto it : st1) cout<<it.first<<" : "<<it.second<<" , ";
        // cout<<endl;
        // for(auto it : st2) cout<<it.first<<" : "<<it.second<<" , ";
        // cout<<endl;
        for(auto it : st1){
            for(int i = 0;i<it.second;i++){
                if(st2.find(it.first) != st2.end()){
                if(st2[it.first] <= 0) return false;
                st2[it.first]--;
                }else return false;
            }
        }
        return true;
    }
};