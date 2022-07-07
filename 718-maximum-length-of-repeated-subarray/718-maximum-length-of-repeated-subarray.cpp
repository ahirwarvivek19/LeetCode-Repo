class Solution {
public:
    #include<bits/stdc++.h>
int f(int ind1,int ind2,vector<int> &s, vector<int> &t,vector<vector<int>> &dp)
{
    if(ind1<=0||ind2<=0)
        return 0;
    if(dp[ind1][ind2]!=-1)
    {
        return dp[ind1][ind2];
    }
    
    if(s[ind1-1]==t[ind2-1])
    {
        return dp[ind1][ind2] = 1+f(ind1-1,ind2-1,s,t,dp);
    }
    else
    {
        return dp[ind1][ind2] = 0;
    }
        
}

int lcs(vector<int>& s, vector<int>& t)
{
    //Write your code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int mx  = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                 dp[i][j] = 0;
            }
            mx = max(mx,dp[i][j]);
        }
    }
    return mx;
    // return f(n,m,s,t,dp);
    
}
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return lcs(nums1,nums2);
    }
};