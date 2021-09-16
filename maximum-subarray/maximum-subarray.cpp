class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum = INT_MIN;
        int csum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            csum+=nums[i];
            msum = max(msum,csum);
            
            if(csum <0)
            {
                csum = 0;
            }
        }
        return msum;
    }
};