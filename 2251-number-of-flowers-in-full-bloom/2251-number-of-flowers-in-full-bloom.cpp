class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // step 1: make map
        map<int,int>mp;
        for(int i=0;i<flowers.size();i++)
        {
            int x=flowers[i][0];
            int y=flowers[i][1];
            mp[x]++;
            mp[y+1]--;
        }
        int sum=0;

        // step 2: copy people array and sort
        vector<int>copy;
        for(int i=0;i<people.size();i++)
        copy.push_back(people[i]);
        sort(copy.begin(),copy.end());
        int pointer1=0;
        //this map is store answer 
        //suppose people[x] answer is y then ans[people[x]]=y
        map<int,int>ans;

        // step 3: visit map and find answer
        for(auto x:mp)
        {
            if(pointer1<copy.size() && x.first<copy[pointer1])
            {
            sum+=x.second;
            }
            else if(pointer1<copy.size() && x.first==copy[pointer1])
            {
                sum+=x.second;
                ans[copy[pointer1]]=sum;
                pointer1++;
            }
            else if(pointer1<copy.size() && x.first>copy[pointer1])
            {
                ans[copy[pointer1]]=sum;
                pointer1++;
                while(pointer1<copy.size() && x.first>copy[pointer1])
                {
                    ans[copy[pointer1]]=sum;
                    pointer1++;
                }
                sum+=x.second;
            }
        }

        // step 4: make final answer array
        vector<int>final_ans;
        for(int i=0;i<people.size();i++)
            final_ans.push_back(ans[people[i]]);
        return final_ans;
    }
};
