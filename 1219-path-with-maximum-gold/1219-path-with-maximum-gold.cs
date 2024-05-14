public class Solution {
    public int GetMaximumGold(int[][] grid) {
        int rows = grid.Length;
        int columns = grid[0].Length;
      bool[,] visited = new bool[rows,columns];
   //   int[,] dp = new int[rows,columns];
        for(int i=0;i<rows;i++)
        {
            for(int j =0;j<columns;j++)
            {
                visited[i,j] = false;
            }
        }
     int ans=0;
            for(int i=0;i<rows;i++)
        {
            for(int j =0;j<columns;j++)
            {
      int p =  helper(grid,visited,i,j,rows,columns);
  if(p>ans)
  ans =p;
            }
        }
       //int ans =0;
       
       return ans;
    }

int helper(int[][] grid,bool[,] visited,int i,int j,int r ,int c)
{
  int a =0;
  int b=0;
  int z=0;
  int d=0;
   if(i>= r || j<0)
   return 0;
   if(visited[i,j] == true)
   return 0;
 

   if(grid[i][j] == 0)
   {
      
       return 0;
   }

  visited[i,j] = true;
  if(i+1<r)
   a = helper(grid,visited,i+1,j,r,c);
  if(j+1 <c)
   b =  helper(grid,visited,i,j+1,r,c);
  if(i-1>=0)
   z =  helper(grid,visited,i-1,j,r,c);
   if(j-1>=0)
   d =  helper(grid,visited,i,j-1,r,c);

   int l = grid[i][j] + Math.Max(a,Math.Max(b,Math.Max(z,d)));
   visited[i,j] = false;
   
   return l;

}

}