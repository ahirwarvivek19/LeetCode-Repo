class Solution {
public:
    int countSubsetSum(vector<int>& nums, int w)
    {
        int n= nums.size();
        int dp[n+1][w+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=w;j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][w];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        
        int s1 = (target+sum)/2;
        
        // int p=(target+s)/2;
        
        if(sum < target || (sum + target) % 2 != 0)
            return 0;
        
        return countSubsetSum(nums,abs(s1));
    }
};