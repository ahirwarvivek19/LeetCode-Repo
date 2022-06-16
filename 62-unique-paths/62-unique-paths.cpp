class Solution {
public:
    int ways(vector<vector<int>> dp, int r, int c)
    {
        if(r<0||c<0)
        {
            return 0;
        }
        if(r==0&&c==0)
            return 1;
        if(r==0)
            return 1;
        if(c==0)
            return 1;
        
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        
        dp[r][c] = ways(dp,r-1,c) + ways(dp,r,c-1);
        
        return dp[r][c];
    }
    
    int printNcR(int n, int r)
    {

        // p holds the value of n*(n-1)*(n-2)...,
        // k holds the value of r*(r-1)...
        long long p = 1, k = 1;

        // C(n, r) == C(n, n-r),
        // choosing the smaller value
        if (n - r < r)
            r = n - r;

        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;

                // gcd of p, k
                long long m = __gcd(p, k);

                // dividing by gcd, to simplify
                // product division by their gcd
                // saves from the overflow
                p /= m;
                k /= m;

                n--;
                r--;
            }

            // k should be simplified to 1
            // as C(n, r) is a natural number
            // (denominator should be 1 ) .
        }

        else
            p = 1;

        // if our approach is correct p = ans and k =1
        return p;
    }
    
    int uniquePaths(int m, int n) {
        
        // vector<vector<int>> dp(101,vector<int>(101,-1));
        // return ways(dp,m-1,n-1);
        
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
        
        // int p1 = (m-1)+(n-1);
        // int p2 = min(n-1,m-1);
        // return printNcR(p1,p2);
            
    }
};