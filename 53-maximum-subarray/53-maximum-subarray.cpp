class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs = 0;
        int ms = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(cs<0)
            {
                cs = 0;
            }
            cs+=nums[i];
            
            ms = max(cs,ms);
        }
        return ms;
    }
};