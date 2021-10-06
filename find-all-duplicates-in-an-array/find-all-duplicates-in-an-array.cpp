class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> v;
        for(auto x: nums)
        {
            if(s.find(x)!=s.end())
            {
                v.push_back(x);
            }
            s.insert(x);
        }
        return v;
    }
};