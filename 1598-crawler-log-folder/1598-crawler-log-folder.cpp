class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>s;
        for(int i = 0;i<logs.size();i++){
            // if(s.empty() && logs[i]!="../" && logs[i]!="./" ){
            //       s.push(logs[i]);
            // }
            if(logs[i]=="../" && !s.empty()){
                s.pop();
            }
             if(logs[i]!="../" && logs[i]!="./" ) {
                s.push(logs[i]);
            }
        }
        return s.size();
    }
};