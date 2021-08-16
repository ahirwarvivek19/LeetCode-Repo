class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         int n=nums.size();
        vector<bool>temp(n+1,false);  
        for(int i=0;i<n;i++)
        {
            if(nums[i]>n||nums[i]<=0)
                continue;
            else
            {
                temp[nums[i]]=true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(temp[i]==false)
                return i;
        }
        return n+1;
    }
};