class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        int pos = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                cnt++;
            else
            {
                nums[pos++] = nums[i];
            }
        }
        for(int i=pos;i<n;i++)
        {
            nums[i]=0;
        }
       
    }
};