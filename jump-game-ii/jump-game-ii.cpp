class Solution {
public:
    int jump(vector<int>& nums) {
        
       int n = nums.size();
        
       vector<int> dp(n,INT_MAX-100); 
        
        dp[0]=0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(i<=j+nums[j])
                {
                    dp[i]=min(dp[i],dp[j]+1);
                }
                
            }
        }
        
        return dp[n-1];
                
    }
};