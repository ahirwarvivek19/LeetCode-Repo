#define mod 1000000007
class Solution {
    int nn;
    // const int mod = 1e9+7;
private:
    int f(int ind,bool sp,vector<vector<int>> &dp)
    {
        if(ind==nn+1)
        {
            if(sp==false)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(ind>nn)
        {
           return 0; 
        }
        
        if(dp[ind][sp]!=-1)
            return dp[ind][sp];
        
        long long cnt = 0;
        if(sp)
        {
            cnt+=f(ind+1,false,dp);
            cnt+=f(ind+1,true,dp);
        }
        else
        {
            cnt+=f(ind+1,false,dp);
            cnt+=f(ind+2,false,dp);
            cnt+=2*f(ind+2,true,dp);
        }
        return dp[ind][sp] = cnt%mod;
        
    }
public:
    int numTilings(int n) {
        nn=n;
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        return f(1,false,dp);
    }
};