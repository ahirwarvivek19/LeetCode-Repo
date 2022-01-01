class Solution {
public:
    int dp[505][505];
    int MCM(vector<int>& nums,int i,int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mx = INT_MIN;
        for(int k=i;k<=j-1;k++){
            int temp = MCM(nums,i,k)+MCM(nums,k+1,j)+nums[i-1]*nums[k]*nums[j];
            mx = max(temp,mx);
        }
        return dp[i][j] = mx;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        n+=2;
        memset(dp,-1,sizeof(dp));
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        return MCM(nums,1,n-1);
    }
};