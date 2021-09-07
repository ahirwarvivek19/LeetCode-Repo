class Solution {
public:
    int dp[1002];
    int rec(int i, vector<int>&cost)
    {
        if(i>=cost.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        int s1 = rec(i+1,cost);
        
        int s2 = rec(i+2,cost);
        
        return dp[i] = min(s1,s2)+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(rec(0,cost),rec(1,cost));
    }
};