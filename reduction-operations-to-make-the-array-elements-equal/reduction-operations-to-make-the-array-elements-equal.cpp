class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;
        
        for(int x: nums)
        {
            mp[x]++;
        }
        
        vector<int> vals;
        
        for(auto x:mp)//unique vals
        {
            vals.push_back(x.first);
        }
        
        reverse(vals.begin(),vals.end());
        
        vals.pop_back();
        
        int tot = 0;
        int ans = 0;
        
        for(int  x: vals)
        {
            tot += mp[x];
            ans += tot;
        }
        return ans;
    }
};