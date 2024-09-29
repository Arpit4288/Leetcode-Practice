class AllOne {
    map<string,int> mp;
    set<pair<int,string>, greater<pair<int,string>>> maxi;
    set<pair<int,string>> mini;
public:
    AllOne() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        mp.clear();
        maxi.clear();
        mini.clear();
    }
    
    void inc(string key) {
        if(!mp.count(key)){
            mp[key] = 1;
            mini.insert({1,key});
            maxi.insert({1,key});
        }
        else{
            int prev = mp[key];
            mp[key] += 1;
            mini.erase({prev,key});
            mini.insert({prev+1,key});
            maxi.erase({prev,key});
            maxi.insert({prev+1,key});
        }
    }
    
    void dec(string key) {
        int prev = mp[key];
        mini.erase({prev,key});
        maxi.erase({prev,key});
        if(--mp[key]==0){
            mp.erase(key);
        }
        else{
            mini.insert({prev-1,key});
            maxi.insert({prev-1,key});
        }
    }
    
    string getMaxKey() {
        if(maxi.empty()) return "";
        else return (*maxi.begin()).second;
    }
    
    string getMinKey() {
        if(mini.empty()) return "";
        else return (*mini.begin()).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */