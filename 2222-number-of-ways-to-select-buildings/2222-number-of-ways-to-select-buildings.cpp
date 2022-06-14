long long dp[100006][3][4];
class Solution {
public:
    long long f(string &s,int i, char par, int cnt)
    {
        
        if(cnt==3)
        {
            return 1;
        }
        
        if(i>=s.size())
            return 0;
            
        if(dp[i][par-'0'][cnt]!=-1)
            return dp[i][par-'0'][cnt];
        
        long long chose=0,nchose=0;
        if(s[i]!=par)
            chose = f(s,i+1,s[i],cnt+1);
        nchose = f(s,i+1,par,cnt);
        
        return dp[i][par-'0'][cnt] = (chose+nchose);
    }
    
    long long numberOfWays(string s) {
        memset(dp,-1,sizeof dp);
        return f(s,0,'2',0);
    }
};