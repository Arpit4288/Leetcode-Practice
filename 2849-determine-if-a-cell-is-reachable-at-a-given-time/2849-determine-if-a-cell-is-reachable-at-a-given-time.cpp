class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy){
            if(t==1)return false;
            return true;
        }
        int min_dis=max(abs(sy-fy),abs(sx-fx));
        if(t<min_dis)return false;
        return true;
    }
};