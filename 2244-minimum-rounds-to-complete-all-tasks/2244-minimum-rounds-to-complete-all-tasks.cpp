class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> freq; // for storing the freq of every element in tasks
        for(auto level : tasks){ // traversing the tasks array
            freq[level]++; // stroing the frequency
        }
        int ans = 0;
        for(auto it : freq){ // traversing freq map
            int levels = it.second;
            int two = 0, three = 0; // number of factors of 2 and 3 initially
            while(levels){
                if(levels %3 != 0 && levels % 2 != 0){
                    levels -= 3;
                    three++;
                }
                else{
                    if(levels %3 == 0 && levels % 2 == 0){
                        levels -= 3;
                        three++;
                    }
                    else{
                        if(levels%3 == 0){
                            levels -= 3;
                            two++;
                        }
                        else{
                            levels -= 2;
                            three++;
                        }
                    }
                }
                if(levels <= 1 && levels != 0){
                    return -1;
                }
            }
            ans += (two + three);
        }
        return ans;
        
    }
};







































