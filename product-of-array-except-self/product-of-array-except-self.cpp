class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int p = 1;
        vector<int> v(n,0);
        int cnt =0;
        for(auto &x:nums)
        {
            if(x)
            {
                p*=x;
            }
            else
            {
                cnt++;
            }
            
        }
                
        if(cnt>=2)
        {
            return v;
        }
        else if(cnt==1)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    v[i] = p;
                }
                else
                {
                    v[i]=0;
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                v[i]= p/nums[i];
            }
        }
        
        return v;
    }
};