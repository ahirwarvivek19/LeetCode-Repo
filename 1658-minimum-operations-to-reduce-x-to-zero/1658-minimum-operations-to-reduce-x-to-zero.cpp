class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        int l = 0,r = 0;
        int cs = 0;
        while(r<n)
        {
            cs+=nums[r];
            
            while(l<=r&&cs>(sum-x))
            {
                cs-=nums[l];
                l++;
            }
            
            if(cs==(sum-x))
                ans = max(r-l+1,ans);
            r++;
        }
        
        if(ans==-1)
            return -1;
        return n-ans;
    }
};