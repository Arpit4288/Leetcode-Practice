class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        if(n==1) return s;
        
        int i=0;
        int j=1;
        bool flag=false;
        while(j<n){
            if(s[i]==s[j]){
                i=j;
                while(j<n && s[i]==s[j]){
                    j++;
                }
                if(j==n){
                flag=true;
                continue;
                } 
                swap(s[i],s[j]);
            }
            i++;
            j=i+1;
        }
        if(flag){
            reverse(s.begin(),s.end());
            //Same stuff that was done from line 7-24 except now if there are matching characters at the end return an empty string, I know i should and could have created a function
            i=0;
            j=i+1;
            while(j<n){
            if(s[i]==s[j]){
                i=j;
                while(s[i]==s[j]) j++;
                if(j==n){
            //The only different thing
                    return "";
                } 
                swap(s[i],s[j]);
            }
            i++;
            j=i+1;
        }
        }
        return s;
    }
};