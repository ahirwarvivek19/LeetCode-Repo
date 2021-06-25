class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int k= coins.size();
        
        int dp[100000]={0};
        
        for(int i=1;i<=amt;i++)
        {
            int ans  = INT_MAX-2;
            for(int j=0;j<k;j++)
            {
                if(i-coins[j]>=0)
                {
                int sub = dp[i-coins[j]];
                ans = min(ans,sub+1);
                }
            }
            dp[i]=ans;
        }
        return (dp[amt]==(INT_MAX-2))?-1:dp[amt];
        
    }
};