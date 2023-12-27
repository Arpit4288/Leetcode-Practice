class Solution {
public:
    int minCost(string s, vector<int>& arr) {
        int n = s.length();
        int prev = 0;
        int next = 1;
        int time = 0;
        while(next<n){
            if(s[prev] == s[next]){
                // cout<<"1st If : "<<s[prev]<<" "<<s[next]<<endl;
                if(arr[prev] <= arr[next]){
                    // cout<<"2nd If : "<<s[prev]<<" "<<s[next]<<endl;
                    s[prev] = -1;
                    time += arr[prev];
                    prev = next;
                    next++;
                }
                else{
                    // cout<<"1st Else : "<<s[prev]<<" "<<s[next]<<endl;
                    s[next] = -1;
                    time += arr[next];
                    next++;
                }
            }
            else{
                // cout<<"2nd Else : "<<s[prev]<<" "<<s[next]<<endl;
                prev = next;
                next++;
            }
        }
        return time;
        
    }
};