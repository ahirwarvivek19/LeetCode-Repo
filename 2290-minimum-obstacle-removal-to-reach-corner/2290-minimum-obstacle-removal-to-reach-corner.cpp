int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
class Solution {
public:
    bool isSafe(int x,int y,int n,int m)
    {
        if(x>=0 and y>=0 and x<n and y<m)
            return true;
        return false;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        deque<pair<int,int>> q;
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        
        
        
        q.push_front({0,0});
        vis[0][0] = true;
        dp[0][0] = 0;
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop_front();
            int x = p.first;
            int y = p.second;
            
            for(int i = 0;i<4;i++)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                
                if(newx>=0 && newy>=0 && newx<n && newy<m)
                {
                    if(!vis[newx][newy])
                    {
                        dp[newx][newy] = dp[x][y] + (grid[newx][newy]==1);
                        if(grid[newx][newy]==1)
                            q.push_back({newx,newy});
                        else
                            q.push_front({newx,newy});
                        vis[newx][newy] = true;
                    }
                    
                }
            }
        }
        
        return dp[n-1][m-1];
        
        
        
    }
};