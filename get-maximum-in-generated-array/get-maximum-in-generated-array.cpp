class Solution {
public:
    int getMaximumGenerated(int n) {
        int dp[n+2];
        
        dp[0]=0;
        dp[1]= 1;
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        int mx = 0;
        for(int i=1;i<=n/2;i++)
        {
            if(2*i >= 2 && 2*i <= n)
                dp[2*i] = dp[i];
            if(2*i +1 >= 2 && 2*i+1 <= n)
                dp[2*i+1] = dp[i]+dp[i+1];
            mx = max(mx,dp[i]);
            mx = max(mx,dp[2*i]);
            mx = max(mx,dp[2*i+1]);
        }
        return mx;
    }
};