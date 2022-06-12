class Solution {
public:
    vector<int> dp;
    int f(int i)
    {
        if(i<=0)
        {
            return 0;
        }
        else if(i<=2)
        {
            return i;
        }
        else if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i] = f(i-1)+f(i-2);
    }
    
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        
        return f(n);
        
    }
};