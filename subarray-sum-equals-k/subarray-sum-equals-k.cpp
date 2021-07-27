class Solution {
public:
    int subarraySum(vector<int>& nums, int sum) {
        map<int,int> mp;
        int ans=0;
        int csum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            csum+= nums[i];
            
            if(csum==sum)
            {
                ans++;
            }
            
            if(mp.find(csum-sum)!=mp.end())
            {
                ans+= mp[csum-sum];
            }
            
            mp[csum]++;
        }
        return ans;
    }
};