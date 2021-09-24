class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = -1;
        int l  = 0;
        int r  = nums.size()-1;            
    
        while(l<=r)
        {
            int mid = (l+(r-l)/2);
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]<target)
            {
                res = mid;
                l = mid+1;
            }  
            else
                r = mid-1;
        }

        return res+1;
    }
};