class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto &it : s) mp[it]++;

        vector<pair<int, char>> vec;

        for(auto &it : mp) vec.emplace_back(make_pair(it.second, it.first));
        sort(vec.begin(), vec.end());

        s = "";
        
        for(auto &it : vec){
            string temp = "";
            for(int i = 0;i<it.first;i++){
                temp += it.second;
            }
            s = temp + s;
        }
        return s;

    }
};