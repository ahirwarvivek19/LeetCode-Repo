class Solution {
public:
    bool isSafe(int x,int y,int n)
    {
        if(x>=0&&x<n&&y>=0&&y<n)
        {
            return true;
            
        }
        return false;
    }
        
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> dx = {1,0,1,0,-1,-1,1,-1};
        vector<int> dy = {1,1,0,-1,0,-1,-1,1};
        queue<pair<int,int>> q;
        if(grid[0][0]!=0)
            return -1;
        q.push({0,0});
        grid[0][0] = 2;
        int n = grid.size();
        int level = 0;
        while(!q.empty())
        {
            level++;
            int ss = q.size();
            for(int j=0;j<ss;j++)
            {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if(x==n-1&&y==n-1)
                    return level;
                for(int i=0;i<8;i++)
                {
                    int newx = x+dx[i];
                    int newy = y+dy[i];

                    if(isSafe(newx,newy,n)&&grid[newx][newy]==0)
                    {
                        q.push({newx,newy});
                        grid[newx][newy] = 2;
                    }
                }
            }
            
        }
        
        return -1;
        
        
    }
};