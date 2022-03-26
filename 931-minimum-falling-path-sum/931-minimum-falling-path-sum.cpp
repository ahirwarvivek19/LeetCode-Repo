class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int j=0;j<n;j++)
        {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int u = matrix[i][j] + dp[i-1][j];
                
                int ul = matrix[i][j],ur=matrix[i][j];
                if(j-1>=0)
                {
                    ul += dp[i-1][j-1];
                }
                else
                {
                    ul += 10000000;
                }
                if(j+1<n)
                {
                    ur += dp[i-1][j+1];
                }
                else
                {
                    ur += 10000000;
                }
                dp[i][j] = min(u,min(ul,ur));
            }
        }
        int mn = INT_MAX;
        for(int j=0;j<n;j++)
        {
            mn = min(mn,dp[n-1][j]);
        }
        return mn;
    }
};