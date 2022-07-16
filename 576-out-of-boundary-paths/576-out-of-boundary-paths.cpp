const int MOD = 1e9+7;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
class Solution {
public:
    int dp[52][52][52];
    
    int f(int m, int n, int mov, int i, int j)
    {
        if(i<0||j<0||i>=m||j>=n)
            return 1;
        if(mov<=0)
            return 0;
        if(dp[i][j][mov]!=-1)
            return dp[i][j][mov];
        int ans = 0;
        
        for(int k=0;k<4;k++)
        {
            int newx = i+dx[k];
            int newy = j+dy[k];
            ans = (ans%MOD + f(m,n,mov-1,newx,newy)%MOD)%MOD;
        }
        return dp[i][j][mov] = ans%MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        
        return f(m,n,maxMove,startRow,startColumn);
    }
};