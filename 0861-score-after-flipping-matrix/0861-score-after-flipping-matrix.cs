public class Solution {
    public int MatrixScore(int[][] grid) {
        int r=grid.Length;
        int c=grid[0].Length;
        for(int i=0;i<r;i++)
            if(grid[i][0]==0)
            {
                // changed=true;
                for(int j=0;j<c;j++)
                    grid[i][j]=grid[i][j]==0?1:0;
            }

        for(int j=1;j<c;j++)
        {   
            int zeroCount=0;
            for(int i=0;i<r;i++)
            {
                if(grid[i][j]==0)
                    zeroCount++;
            }

            if(r-zeroCount<zeroCount)
            {
                // changed=true;
                for(int i=0;i<r;i++)
                {
                    grid[i][j]=grid[i][j]==0?1:0;
                }
            }
        }

        
        // }

        int sum=0;
        for(int i=0;i<r;i++){
            // Console.WriteLine();
            // for(int j=0;j<c;j++)
            //     Console.Write(grid[i][j]+"  ");

            int num=0;
            for(int j=c-1;j>=0;j--)
            {

                if(grid[i][j]==1)
                    num+=(int)Math.Pow(2, (c-1)-j);
            }

            sum+=num;
        }

        return sum;
    }
}