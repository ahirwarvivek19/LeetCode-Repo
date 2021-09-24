class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX;
        int profit=0;
        
        for(int i=0;i<prices.size();i++)
        {
            minP=min(minP,prices[i]);
            profit=max(profit,prices[i]-minP);
        }
        return profit;
    }
};