class Solution {
public:
    bool f(int ind, int sum,vector<int> &nums,vector<vector<int>> &dp)
    {
        int n = nums.size();
        if(ind<0||sum<0)
            return false;
        if(sum==0)
            return true;
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        bool cc = f(ind-1,sum-nums[ind],nums,dp)|f(ind-1,sum,nums,dp);
        return dp[ind][sum] = cc;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum  = 0;
        int n = nums.size();
        
        for(int i = 0;i<n;i++)
            sum+=nums[i];
        vector<vector<int>> dp(n,vector<int> (sum/2+1,-1));
        if(sum%2==0)
            return f(n-1,sum/2,nums,dp);
        else 
            return false;
    }
};