class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> map;
        for(auto it : stones){
            map[it] = unordered_set<int>();
        }
        map[0].insert(1);
        for(int i = 0; i < stones.size(); i++){
            for(auto it : map[stones[i]]){
                if(map.find(stones[i] + it) != map.end()){
                    if(stones[i] + it == stones[stones.size() -1]) return true;
                    if(it - 1 != 0) map[stones[i] + it].insert(it - 1);
                    map[stones[i] + it].insert(it);
                    map[stones[i] + it].insert(it + 1);
                }
            }
        }
        return false;
    }
};