class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<int> dp(mx + 1, 0);
        
        for(auto x : nums) dp[x] += x;
        
        for(int i = 2; i <= mx; i++){
            dp[i] = max(dp[i] + dp[i - 2], dp[i - 1]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};