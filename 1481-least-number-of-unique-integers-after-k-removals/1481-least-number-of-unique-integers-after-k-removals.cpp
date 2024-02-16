class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int, int>::iterator it;
        for(it = mp.begin();it!=mp.end();it++){
            pq.push({it->second, it->first});
        }

        for(int i=0;i<k;i++){
            if(pq.empty())
                return 0;
            pair<int,int> tmp = pq.top();
            pq.pop();
            tmp.first--;
            if(tmp.first){
                pq.push({tmp.first,tmp.second});
            }
        }
        return pq.size();
    }
};