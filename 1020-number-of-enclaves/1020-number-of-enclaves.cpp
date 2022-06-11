int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


int cnt = 0;
class Solution {
public:
    bool isSafe(int i,int j,vector<vector<int>> & grid)    
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i>=0&&j>=0&&i<n&&j<m&&grid[i][j]==1)
        {
            return true;
        }
        return false;
    }
    void dfs(int i,int j,vector<vector<int>> & grid)
    {
        cnt++;
        grid[i][j]=0;
        
        for(int k=0;k<4;k++)
        {
            int x = i+dx[k];
            int y = j+dy[k];
            if(isSafe(x,y,grid))
            {
                dfs(x,y,grid);
            }
        }
        
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt1 = 0;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    if(grid[i][j]==1)
                        dfs(i,j,grid);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt1++;
                }
            }
        }
        cout<<cnt<<endl;
        cout<<cnt1<<endl;
        // if(cnt1==cnt)
        //     return 0;
        // int ans = cnt1-cnt;
        // if(ans<=0)
        //     return 0;
        return cnt1;
    }
};