class Solution {
public:

    string shortestCommonSupersequence(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        string res = "";
        
        for(int i = n,j=m;i||j;)
        {
            if(i>0 &&dp[i][j]==dp[i-1][j])
            {
                res = s[i-1]+res;
                i--;
            }
            else if(j>0 &&dp[i][j]==dp[i][j-1])
            {
                res = t[j-1]+res;
                j--;
            }
            else
            {
                res = s[i-1]+res;
                i--,j--;
            }
        }
        
        return res;
    }
};