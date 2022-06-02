int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
// int sc = 0;

class Solution {
public:
    bool isSafe(int x,int y,vector<vector<int>>& grid)
    {
        
        int r,c;
        r=grid.size();
        c= grid[0].size();
        if(x>=0 && x<r && y>=0 && y<c && grid[x][y]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void fill(int x,int y,vector<vector<int>>& grid)
    {
        grid[x][y] = 1;
        int n= grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++)
        {
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(isSafe(newx,newy,grid))
            {
                fill(newx,newy,grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    if(grid[i][j]==0)
                        fill(i,j,grid);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if(i==0||j==0||i==n-1||j==m-1)
                // {
                
                    if(grid[i][j]==0)
                    {
                        cnt++;
                        fill(i,j,grid);
                    }    
                // }
            }
        }
        return cnt;
    }
};