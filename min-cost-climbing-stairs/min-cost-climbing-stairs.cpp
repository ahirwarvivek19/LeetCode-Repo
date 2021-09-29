class Solution {
public:
    int dp[1002];
    int minCost(vector<int>& cost, int n)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0||n==1)
        {
            return cost[n];
        }
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n] = cost[n]+min(minCost(cost,n-1),minCost(cost,n-2));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        return min(minCost(cost,n-1),minCost(cost,n-2));
    }
};