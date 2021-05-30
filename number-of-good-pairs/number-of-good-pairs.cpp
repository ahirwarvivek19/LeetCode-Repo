class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count = 0;
        for(auto x: nums)
        {
            if(mp.find(x)!=mp.end())
            {
                count+= mp[x];
            }
            mp[x]++;
        }
        return count;
    }
};