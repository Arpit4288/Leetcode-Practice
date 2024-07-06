class Solution {
public:
    int passThePillow(int n, int t) {
        if(n > t){
            cout<<"DONE"<<endl;
            return t+1;
        }
        bool even = ((t)/(n-1))%2 == 0;
        t = (t)%(n-1);
        if(even) cout<<"yes "<<t<<endl;
        else cout<<"no "<<t<<endl;
        if(even){
            return t+1;
        }
        return n-t;
    }
};