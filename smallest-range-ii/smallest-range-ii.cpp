class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int smallest=nums[0]+k;
        int largest=nums[n-1]-k;
        int mn = nums[n-1]-nums[0];
        
        for(int i=0;i<n-1;i++)
        {
            // int mn=min(smallest,A[i+1]-k);
            // int mx=max(A[i]+k,largest);
            int s = min(nums[i+1]-k,smallest);
            int l = max(nums[i]+k,largest);
            mn = min(l-s,mn);
        }
        return mn;
    }
};