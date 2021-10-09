class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum = 0;
        int msum = INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            csum+=nums[i];
            msum = max(msum,csum);
            if(csum<0)
            {
                csum =0;
            }
        }
               
        return msum;
    }
};