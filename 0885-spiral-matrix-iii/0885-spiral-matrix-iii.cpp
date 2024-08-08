class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Move 1 step in East directon
        // Move 1 step in South direction
        // Move 2 steps in West direction
        // Move 2 steps in North direction
        // Move 3 steps in Eash direction
        // Move 3 steps in South direction
        // ......
        // We are moving as a pairs of directions with equal step size. In other way East and South at the current iteration would be having same step size and then in the next iteration the step size would be increased by one and then west and north will be having same step size that got incremented by one.
        // dr --> (dx, dy)
        vector<vector<int>> dr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int stepSize = 1;
        vector<vector<int>> traversed;
        int dir = 0;
        while(traversed.size() < rows * cols){
            for(int i = 0 ; i <= 1 ; i++){
                for(int j = 0 ; j < stepSize ; j++){
                    if(rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols){
                        traversed.push_back({rStart, cStart});
                    }
                    rStart += dr[dir][0];
                    cStart += dr[dir][1];
                }
                dir = (dir + 1) % 4;
            }
            stepSize++;
        }
        return traversed;
    }
};