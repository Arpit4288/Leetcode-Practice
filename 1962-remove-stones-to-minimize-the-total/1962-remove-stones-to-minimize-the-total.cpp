class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        map<int, int> mp;
        for(auto stones : piles){
            mp[stones]++;
        }
        
        // for(auto it : mp) cout<<it.first<<" : "<<it.second<<endl;
        for(int i = 0;i<k;i++){
            int stones = (mp.rbegin())->first;
            // cout<<"stones : "<<stones<<", ";
            if(mp.rbegin()->second == 1) mp.erase(mp.rbegin()->first);
            else mp[mp.rbegin()->first]--;
            // cout<<"mp values : "<<mp.rbegin()->first<< " | "<<mp.rbegin()->second<<", ";
            stones -= floor(stones/2);
            // cout<<"stones after : "<<stones<<", "<<endl;
            mp[stones]++;
        }
        // for(auto it : mp) cout<<it.first<<" : "<<it.second<<endl;
        int sum = 0;
        for(auto it : mp){
            if(it.second > 0) sum += it.first*it.second;
        }
        return sum;
        
    }
};