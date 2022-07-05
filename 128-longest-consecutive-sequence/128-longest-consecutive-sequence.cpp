class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     
        int n =  nums.size();
        if(n<=0)
            return 0;
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int mx = 0;
        for(int i = 1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
                cnt++;
            else if(nums[i]!=nums[i-1])
            {
                mx=max(cnt,mx);
                cnt = 1;
            }
        }
        mx = max(mx,cnt);
        return mx;
    }
};