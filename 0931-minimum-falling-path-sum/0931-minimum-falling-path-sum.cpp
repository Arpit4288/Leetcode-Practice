class Solution {
public:
    
int minFallingPathSum(vector<vector<int>>& mat) 
{
    int r=mat.size(), c=mat[0].size();
    vector<int> pre(c, 0), cur(c, 0);
    
    for(int j=0; j<c; j++) pre[j] = mat[0][j];
    
    for(int i=1; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            int u = mat[i][j] + pre[j];
            
            int ld=mat[i][j], rd=mat[i][j];
            
            if(j-1>=0) ld += pre[j-1];
            else ld += 1e8;
            
            if(j+1<c) rd += pre[j+1];
            else rd += 1e8;
                
            cur[j] = min(u, min(ld, rd));
        }
        pre = cur;
    }
    
    int mini = 1e8;
    for(int j=0; j<c; j++)
        mini = min(mini, pre[j]);
    
    return mini;    
}
};