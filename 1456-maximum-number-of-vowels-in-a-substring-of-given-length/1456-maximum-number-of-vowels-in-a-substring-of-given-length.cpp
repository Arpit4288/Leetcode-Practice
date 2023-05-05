class Solution {
public:
    int maxVowels(string s, int k) {


        int count=0;

        string s1=s.substr(0,k);
        for(char x:s1){
            if(x=='a' || x=='e' || x=='i'|| x=='o'|| x=='u'){
                count++;       
            }
        }
        if(count==k){
            return k;
        }

        int maxcount=count;
        int j=0;

        for(int i=k;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o'|| s[i]=='u'){
                count++;       
            }
            if(s[j]=='a' || s[j]=='e' || s[j]=='i'|| s[j]=='o'|| s[j]=='u'){
                count--;       
            }
            j++;
            maxcount=max(maxcount,count);
            if(maxcount==k){
                return maxcount;
            }
        }

        return maxcount;
        
    }
};