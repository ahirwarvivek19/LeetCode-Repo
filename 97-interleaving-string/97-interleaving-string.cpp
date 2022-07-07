class Solution {
public:
    
    int n,m ,len;
    
    bool f(string s1, string s2, string s3,int i,int j,int k,vector<vector<vector<int>>> &dp)
    {
        if(i>=n&&j>=m&&k>=len)
            return true;
        if(k>=len)
            return false;
        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        bool op1 = (s1[i]==s3[k])&&f(s1,s2,s3,i+1,j,k+1,dp);
        bool op2 = (s2[j]==s3[k])&&f(s1,s2,s3,i,j+1,k+1,dp);
        
        return dp[i][j][k] = op1||op2;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m = s2.size();
        len = s3.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(len+1,-1)));
        
        return f(s1,s2,s3,0,0,0,dp);
    }
};