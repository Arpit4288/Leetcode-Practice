class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
	
	//For storing the answer
        vector<vector<int>>ans;
		
		//for storing winners with 0 lost matches
        vector<int>col;
		
       //counting total number of wins of each player
        map<int,int>mpw ; 
        for(int j = 0 ; j < matches.size() ; j++){
            for(int i = 0 ; i < 2 ; i++){
                if(i==0){
                    mpw[matches[j][0]]++;
                }
            }
        }
		
		//counting total number of lost matches of each player
        map<int,int>mpl;
        for(int j = 0 ; j < matches.size() ; j++){
            for(int i = 0 ; i < 2 ; i++){
                if(i==1){
                    mpl[matches[j][1]]++;
					
					//when we found any player with losing atleast one match we the wins count = 0
                    mpw[matches[j][1]] = 0;
                }
            }
        }
        for(auto x : mpw){
		//if we found any value zero . Then we can say that the player has lost atleast one match
		//we won't add those players
            if(x.second > 0){
                col.push_back(x.first);
            }
        }
        ans.push_back(col);
        vector<int>row;
        for(auto x : mpl){
            if(x.second==1){
                row.push_back(x.first);
            }
        }
        ans.push_back(row);
        return ans;
    }
};