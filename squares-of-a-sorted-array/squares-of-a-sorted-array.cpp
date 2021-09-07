class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for(auto x: nums)
        {
            res.push_back(x*x);
        }
        sort(res.begin(),res.end());
        return res;
    }
};