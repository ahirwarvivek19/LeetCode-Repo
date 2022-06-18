class Solution {
public:
    int f(int ind,int sum,vector<int>& nums,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(sum==0&&nums[ind]==0)
                return 2;
            if(sum==0||nums[ind]==sum)
                return 1;
            return 0;
        }
            
        // if(ind==0)
        //     return (nums[ind]==sum);
        if(ind<0||sum<0)
            return 0;
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        dp[ind][sum] = f(ind-1,sum,nums,dp);
        if(nums[ind]<=sum)
            dp[ind][sum] += f(ind-1,sum-nums[ind],nums,dp);
        return dp[ind][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        
        int n = nums.size();
        
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        int s1 = (target+sum);
        if(sum < target || (sum + target) % 2 != 0)
            return 0;
        s1/=2;
        vector<vector<int>> dp(n+1,vector<int>(abs(s1)+1,-1));
        return f(n-1,abs(s1), nums,dp);
    }
};