int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
class Solution {
public:
    bool isSafe(int x,int y,int n, int m)
    {
        if(x>=0&&y>=0&&x<n&&y<m)
            return true;
        return false;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
                
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            int x = u.first;
            int y = u.second;
            
            for(int i =0;i<4;i++)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isSafe(newx,newy,n,m)&&dist[newx][newy]==INT_MAX)
                {
                    q.push({newx,newy});
                    dist[newx][newy] = dist[x][y]+1;
                    ans = max(ans,dist[newx][newy]);
                }
            }
        }
        
        if(ans==0)
            return -1;
        else return ans;
    }
};