class Solution
{
public:
    bool isAllStars(string &S1, int i)
    {
        for (int j = 0; j <= i; j++)
        {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

    bool f(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
    {

        // Base Conditions
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
            return isAllStars(S1, i);

        if (dp[i][j] != -1)
            return dp[i][j];

        if (S1[i] == S2[j] || S1[i] == '?')
            return dp[i][j] = f(S1, S2, i - 1, j - 1, dp);

        else
        {
            if (S1[i] == '*')
                return dp[i][j] = (f(S1, S2, i - 1, j, dp) || f(S1, S2, i, j - 1, dp));
            else
                return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

//         for (int i = 1; i <= m; i++)
//             dp[0][i] = p[i - 1] == '*' && i - 1 >= 0 ? dp[0][i - 1] : 0;
//         // when pattern length is zero
//         for (int i = 1; i <= s.size(); i++)
//             dp[i][0] = 0;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 if (s[i - 1] == p[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1];
//                 else
//                 {
//                     if (p[j - 1] == '?')
//                         dp[i][j] = dp[i - 1][j - 1];
//                     else if (p[j - 1] == '*')
//                         dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
//                 }
//             }
//         }

//         return dp[n][m];
        return f(p, s,m-1,n-1, dp);
    }
};