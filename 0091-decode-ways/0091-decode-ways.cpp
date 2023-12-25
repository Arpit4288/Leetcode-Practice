class Solution {
public:
    vector<int> vec;
    int solve(string &s,int i){
        if (i==s.size()) return 1;
        if (i>s.size()) return 0;
        if (s[i]=='0') return 0;
        if (vec[i]!=-1) return vec[i];
        int count = 0;
        count+=solve(s,i+1);
        // cout<<i<<"  "<<s.substr(i,2)<<"  "<<stoi(s.substr(i,2))<<endl;
        if (stoi(s.substr(i,2))<=26){
            count+=solve(s,i+2);
        }
        return vec[i]=count;
    }
        
    int numDecodings(string s) {
        vec = vector<int>(s.size(),-1);
        return solve(s,0);
    }
};