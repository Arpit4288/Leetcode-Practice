class Solution {
public:
    int numSteps(string s) {
        
        int count = 0;
        while(s!="1"){
            count++;
            int len  = s.length();
            if(s[len-1]=='1'){
                bool flag = false;
                for(int j = len-1; j>=0; j--){
                    if(s[j]=='0'){
                        s[j] = '1';
                        s[len-1] = '0';
                        flag = true;
                        break;
                    }
                    else{
                        s[j] = '0';
                    }
                }

                if(!flag){
                    string temp = "1"+s;
                    s = temp;
                }
            }else{
                for(int j = len-1; j>0; j--){
                    if(s[j-1]=='1'){
                        s[j] = '1';
                        s[j-1] = '0';
                    }
                }
                for(int i = 0; i <len; i++){
                    if(s[i]!='0'){
                        string temp = s.substr(i, len - i);
                        s = temp;
                        break; 
                    }
                }
            }
        }
        return count;
    }
};