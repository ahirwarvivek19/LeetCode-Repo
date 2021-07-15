class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        
        if(n==0)
            return false;
        
        int farthest = 0;
        
        for(int i=0;i<n;i++)
        {
            if(farthest<i)
                return false;
            farthest = max(farthest,i+nums[i]);
            
        }
        
        return true;
        
        
        
    }
};