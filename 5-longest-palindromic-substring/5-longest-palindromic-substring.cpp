class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        int mx = 1;
        int start = 0;
        bool dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = true;
                start = i;
                mx = 2;
            }
        }
        
        for(int k=2;k<=n;k++)
        {
            for(int i = 0;i<n-k+1;i++)
            {
                int j = i+k-1;
                
                if(dp[i+1][j-1]==true&&(s[i]==s[j]))
                {
                    dp[i][j] = true;
                    if(k>mx)
                    {
                        start = i;
                        mx = k;
                        
                    }
                    
                }
            }
        }
        
//         string res = "";
        
//         for(int i = st;i<(st+mx-1);i++)
//         {
//             res.push_back(s[i]);
//         }
        return s.substr(start,mx);
    }
};