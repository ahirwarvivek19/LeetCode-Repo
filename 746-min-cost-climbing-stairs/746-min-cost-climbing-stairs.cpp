class Solution {
public:
    int f(int i,vector<int> &cost,vector<int> &dp)
    {
        if(i==0||i==1)
            return cost[i];
        
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i] = cost[i]+min(f(i-1,cost,dp),f(i-2,cost,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==1)
        {
            return cost[0];
        }
        vector<int> dp(n+1,-1);       
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // for(int i=2;i<n;i++)
        // {
        //     dp[i]  = cost[i]+min(dp[i-1],dp[i-2]);
        // }
        // return min(dp[n-1],dp[n-2]);
        
        return min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
};