class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        int n = arr.size();
        long double d;
        // cout<<d<<endl;
        int flag = 0;
        if(arr[1][0] - arr[0][0] != 0) d = ((double)arr[1][1] - (double)arr[0][1]) / ((double)arr[1][0] - (double)arr[0][0]);
        else flag = 1;
        // cout<<d<<endl;
        // cout<<arr[1][1] - arr[0][1] / arr[1][0] - arr[0][0]<<endl;
        for(int i = 1;i<n;i++){
            if(flag == 1){
                // cout<<"1"<<"  ";
                if(((double)arr[i][0] - (double)arr[i-1][0]) != 0){
                     return false;
                    // cout<<"2"<<"  ";
                }
            }
            else{
                // cout<<"3"<<"  ";
                if(((double)arr[i][0] - (double)arr[i-1][0]) == 0){
                    cout<<"4"<<" ";
                    return false;
                }
                else{
                    // cout<<"5"<<" ";
                    if(((double)arr[i][1] - (double)arr[i-1][1]) / ((double)arr[i][0] - (double)arr[i-1][0]) != d){
                        // cout<<"6"<<" ";
                        return false;
                    }
                }
            }
            // cout<<endl;
        }
        return true;
    }
};