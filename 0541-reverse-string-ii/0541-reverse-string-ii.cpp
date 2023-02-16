class Solution {
public:
    
    void rev(string &s, int i, int j){
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    
    string reverseStr(string s, int k) {
        int i = 0;
        while(i < s.size()){
            if(i + k-1 < s.size()){
                rev(s, i, i + k-1);
            }
            else{
                rev(s, i, s.size()-1);
            }
            i += (2*k);
        }
        return s;
    }
};