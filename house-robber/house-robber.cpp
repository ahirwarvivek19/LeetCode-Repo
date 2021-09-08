class Solution {
public:
    int rob(vector<int>& nums) {
        int inc=0,exc=0;
        for(int i=0;i<nums.size();i++)
        {
            int prevI  = inc;
            
            inc = nums[i]+exc;
            
            exc = max(exc,prevI);
        }
        return max(inc,exc);
        
        
        
    }
};