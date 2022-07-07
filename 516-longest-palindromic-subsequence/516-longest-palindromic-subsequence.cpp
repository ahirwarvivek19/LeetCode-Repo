class Solution {
public:
    
    int lcs(string a,string b)
    {
        int m = a.length();
        int n = b.length();
        
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    int longestPalindromeSubseq(string s) {
        string b = s;
        
        reverse(b.begin(),b.end());
        
        return lcs(s,b);
    }
};