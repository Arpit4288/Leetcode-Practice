class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s =0;
        int e =letters.size()-1;
        char smchar = letters[0];
        
        while(s<=e){
            int mid = (s+e)/2;
            
            if(letters[mid] > target){
                e =mid-1;
                smchar = letters[mid];
            }
            else{
                s=mid+1;
            }
        }
        return smchar;
    }
};