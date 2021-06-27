
vector<int> dp(100000,-1);
class Solution {
public:
    int numSquares(int n) {
        
        if(n==0)
            return 0;
        
        int root = sqrt(n);
        if(root*root==n)
        {
            return 1;
        }
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        int ans = n;
        for(int i=1;i*i<=n;i++)
        {
            ans = min(ans,1+numSquares(n-i*i));
        }
        
        return dp[n]=ans;
        
        
        
    }
};