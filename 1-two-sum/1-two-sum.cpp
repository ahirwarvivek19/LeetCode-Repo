class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int csum = 0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int t = target-nums[i];
            
            if(mp.find(t)!=mp.end())
            {
                
                v.push_back(mp[t]);
                v.push_back(i);
            }
            
            mp[nums[i]]=i;
        }
        
        return v;
    }
};