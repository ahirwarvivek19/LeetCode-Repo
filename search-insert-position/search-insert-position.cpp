class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = nums.size();
        int l=0;
        int r= nums.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(target==nums[mid])
            {
                pos=mid;
                break;
            }
            
            else if(target<nums[mid])
            {
                pos = mid;
                r=mid-1;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
        }
        
        return pos;
    }
};