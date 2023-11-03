class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int initialVal=1; //Take the initial Value 
        vector<string> ans; //Final ans to return
        string push="Push";
        string pop="Pop";
        for(auto x:target)
        {
            if(x==initialVal) //Check if the values matches to inital Value
            {
                ans.push_back(push);
            }
            else
            {
                while(initialVal<x){ //Increase initialVal till it macthes with the current value
                    ans.push_back(push);
                    ans.push_back(pop);
                    initialVal++;
                }
                ans.push_back(push);
            }
            initialVal++;//Increment of Initial Value
        }
        return ans;//Return ans
    }
};