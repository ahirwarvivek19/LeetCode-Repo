class Solution {
public:
    bool check(vector<int>& nums, int m,int mid)
    {
        int n = nums.size();
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                cnt++;
                sum=nums[i];
                if(sum>mid)
                {
                    return false;
                }
            }
            
        }
        if(cnt>m)
        {
            return false;
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int sum = 0;
        for(auto &x:nums)
        {
            sum+=x;
        }
        
        if(m==1)
        {
            return sum;
        }
        
        int l = 0;
        int n = nums.size();
        int r = sum;
        int res = INT_MAX;
        while(l<=r)
        {
            int mid  = (r-l)/2+l;
            
            if(check(nums,m,mid))
            {
                res = min(res,mid);
                r= mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return res;
        
    }
};