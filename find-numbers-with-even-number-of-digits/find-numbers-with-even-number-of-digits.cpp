class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto x: nums)
        {
            string s = to_string(x);
            int n = s.size();
            if(n%2==0)
            {
                cnt++;
            }
            else
            {
                continue;
            }
        }
        return cnt;
        
    }
};