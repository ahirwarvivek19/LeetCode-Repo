#define mod 1000000007

class Solution {
public:
    
    int numTilings(int n) {
        vector<long long >dp(n+1,0);
        if(n==1) return 1;
        if(n==2) return 2;                            //Base Cases
        if(n==3) return 5;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++)
        {
            dp[i]=((2*dp[i-1])%mod+(dp[i-3])%mod)%mod;
        }
        return dp[n];
    }
};