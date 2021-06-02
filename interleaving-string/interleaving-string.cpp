class Solution {
public:
    
    bool fun(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>> &dp) {
        if (i == s1.length()) {
            return s2.substr(j) == (s3.substr(k));
        }
        if (j == s2.length()) {
            return s1.substr(i) == (s3.substr(k));
        }
        if (dp[i][j] >= 0) {
            return dp[i][j];
        }
        bool ans = false;
        if (s3[k] == s1[i] && fun(s1, i + 1, s2, j, s3, k + 1, dp)
                || s3[k] == s2[j] && fun(s1, i, s2, j + 1, s3, k + 1, dp)) {
            ans = true;
        }
        return dp[i][j] = ans ;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
         int a=s1.size();
        int b=s2.size();
        int c=s3.size();
        
         if (a + b != c) {
            return false;
        }
        vector<vector<int>> dp(a,vector<int>(b,-1));
        return fun(s1, 0, s2, 0, s3, 0, dp);
    }
};