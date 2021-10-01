class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int sizeC=0;
    bool isSafe(int x,int y,vector<vector<int>>& grid)
    {
        
        int r,c;
        r=grid.size();
        c= grid[0].size();
        if(x>=0 && x<r && y>=0 && y<c && grid[x][y]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void dfs(int x,int y, vector<vector<int>>& grid)
    {
        grid[x][y]='0';
        sizeC++;
        for(int k=0;k<4;k++)
        {
            int newx = x+dx[k];
            int newy = y+dy[k];
            if(isSafe(newx,newy,grid))
            {
                dfs(newx,newy,grid);
            }
        }
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int  cnt=0;
        int ans = 0;
        int r,c;
        r=grid.size();
        c= grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    sizeC = 0;
                    cnt++;
                    dfs(i,j,grid);
                    ans = max(ans,sizeC);
                }
            }
        }
        
        return ans;
        
    }
};