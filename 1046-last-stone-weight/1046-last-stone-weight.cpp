class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        priority_queue<int> pq;
        for(auto it : stones){
            pq.push(it);
        }
        while(pq.size() != 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int res;
            if(x == y){
                pq.push(0);
                continue;
            }
            if(x < y){
                pq.push(y-x);
            }
            else{
                pq.push(x-y);
            }
        }
        return pq.top();
    }
};