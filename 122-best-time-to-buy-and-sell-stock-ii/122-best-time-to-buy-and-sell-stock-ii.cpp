class Solution {
public:
    int n ;
    int f(int i,int buy,vector<int>& prices, vector<vector<int>> &dp)
    {
        if(i==n)
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int ch = 0;
        if(buy==0)
        {
            ch = max(-prices[i]+f(i+1,1,prices,dp),0+f(i+1,0,prices,dp));
        }
        else if(buy==1)
        {
            ch = max(prices[i]+f(i+1,0,prices,dp),0+f(i+1,1,prices,dp));
        }
        return dp[i][buy] = ch;
    }
        
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,0,prices,dp);
         // max(dp[0][0],dp[0][1]);
    }
};