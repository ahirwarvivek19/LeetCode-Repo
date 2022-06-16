class Solution {
public:
    
    int f(int i , int j1,int j2,vector<vector<int>>& a, vector<vector<vector<int>>> &dp)
    {
        int n = a.size();
        int m = a[0].size();
        if(i<0||j1<0||j1>=m||j2<0||j2>=m)
            return -1e8;
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        if(i==n-1)
        {
            if(j1==j2)
                return dp[i][j1][j2]=a[i][j1];
            else
                return dp[i][j1][j2]=a[i][j1]+a[i][j2];
        }
        int maxi = 0;
        for(int dj1 =-1;dj1<=1;dj1++)
        {
            for(int dj2 =-1;dj2<=1;dj2++)
            {
                int value = a[i][j1];
                if(j1!=j2)
                    value+=a[i][j2];
                value+=f(i+1,j1+dj1,j2+dj2,a,dp);
                maxi  = max(maxi,value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
        
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        return f(0,0,m-1,grid,dp);
        
    }
};