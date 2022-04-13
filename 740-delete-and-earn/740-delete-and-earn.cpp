class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> mp(20005,0);
        vector<int> dp(20005,0);
        int  mx = nums[0];
        for(auto x:nums)
        {
            mp[x]++;
            mx = max(mx,x);
        }
        
        dp[1] = mp[1];
        // dp[2] = max(mp[2]*2,dp[1]);
        
        for(int i=2;i<=mx;i++)
        {
            dp[i] = max(i*mp[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[mx];
    }
};