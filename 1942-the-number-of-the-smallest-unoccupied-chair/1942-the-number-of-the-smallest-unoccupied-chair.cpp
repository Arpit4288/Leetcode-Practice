class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        vector<pair<int, pair<int,int>> > v;

        for(int i=0;i<times.size();i++){
            v.push_back(make_pair(times[i][0], make_pair(times[i][1],i)));
        }

        sort(v.begin(), v.end());

        int c=-1;
        priority_queue<int, vector<int>, greater<int> > pos;
        vector<int> val(times.size(),-1);

        for(int i=0;i<v.size();i++){

            while(!pq.empty() && times[pq.top().second][1]<=v[i].first){
                pos.push(val[pq.top().second]);
                pq.pop();
            }

            if(!pos.empty()){
                val[v[i].second.second] = pos.top();
                pos.pop();
                
            }
            else{
                c++;
                val[v[i].second.second] = c;
            }

            pq.push(make_pair(v[i].second.first, v[i].second.second));

         //   cout<<val[v[i].second.second]<<" for "<<v[i].second.second<<endl;

            if(v[i].second.second==targetFriend) return val[v[i].second.second];

        }

        return -1;
    }
};