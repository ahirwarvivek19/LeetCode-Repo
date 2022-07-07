class Solution {
public:
int f(int ind1,int ind2,string &s, string &t,vector<vector<int>> &dp)
{
    if(ind1<=0||ind2<=0)
        return 0;
    if(dp[ind1][ind2]!=-1)
    {
        return dp[ind1][ind2];
    }
    
    if(s[ind1-1]==t[ind2-1])
    {
        return dp[ind1][ind2] = 1+f(ind1-1,ind2-1,s,t,dp);
    }
    else
    {
        return dp[ind1][ind2] = max(f(ind1-1,ind2,s,t,dp),
                                    f(ind1,ind2-1,s,t,dp));
    }
        
}

int lcs(string s, string t)
{
    //Write your code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                 dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
    return f(n,m,s,t,dp);
    
}
    
    int minInsertions(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        
        return s.size()-lcs(s,r);
        
    }
};