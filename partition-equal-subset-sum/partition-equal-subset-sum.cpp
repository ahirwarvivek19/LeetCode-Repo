class Solution {
private:
    bool func(int ind, int sum,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(sum<0)
        {
            return 0;
        }
        if(ind==nums.size())
        {
            return sum==0;
        }
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];

        bool pick = func(ind+1,sum-nums[ind],nums,dp);
        
        bool nonpick = func(ind+1,sum,nums,dp);
        
        return dp[ind][sum] = pick|nonpick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x:nums)
        {
            sum+=x;
        }
        if(sum&1)
        {
            return false;
        }
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        // find subset with sum = sum/2
        
        return func(0,sum/2,nums,dp);
        
        
    }
};