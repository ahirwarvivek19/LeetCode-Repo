class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> res;
        
        for(int i=0;i<nums.size();i++)
        {
            int index = nums[i];
            if(nums[abs(index)-1]>0)
            {
                nums[abs(index)-1] = -nums[abs(index)-1];
                
            }
        }
        
        for(int i=1;i<=nums.size();i++)
        {
            if(nums[i-1]>0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};