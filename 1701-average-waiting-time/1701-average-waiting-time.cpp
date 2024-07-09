class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double  sum =customers[0][1];
        double  time =customers[0][0]+customers[0][1];
         for(int i = 1;i<customers.size();i++){
            if((time-customers[i][0])>0){
                sum+=time-customers[i][0]+customers[i][1];
                time = time+customers[i][1];
            }
            else{
                sum+=customers[i][1];
                time = customers[i][0]+customers[i][1];
            }
         }
        double a = (sum) / customers.size();

         return a;
    }
};