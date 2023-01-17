class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1 = 0, numberOfFlips = 0; // initializing the count of 1 and numberoflips as 0
        for(auto &c : s){
            if(c == '1'){
                // no need to flip it will not impact our answer
                // simply increase the count1 by 1
                count1++;
            }
            else{
                // if c == '0'
                // we need to check two condition whether we can flip this 0 to 1 or we can flip all 1 to 0 which we have counted so far we have to take min of it
                numberOfFlips++;  // if we flip 0 to 1;
            }
            numberOfFlips = min(count1, numberOfFlips);
        }
        return numberOfFlips;
    }
};