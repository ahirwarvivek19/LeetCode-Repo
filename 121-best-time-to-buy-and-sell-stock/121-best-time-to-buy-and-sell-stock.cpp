class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int mx = 0;
        for(int i=0;i<prices.size();i++)
        {
            mx = max(prices[i]-mn,mx);
            mn = min(prices[i],mn);
        }
        return mx;
    }
};