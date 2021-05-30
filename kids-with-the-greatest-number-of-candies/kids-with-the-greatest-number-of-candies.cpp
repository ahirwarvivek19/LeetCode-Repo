class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int mx = candies[0];
        vector<bool> vis(n,false);
        for(auto x: candies)
        {
            mx = max(x,mx);
        }
        
        for(int i=0;i<candies.size();i++)
        {
            if((candies[i]+extraCandies)>=mx)
            {
                vis[i]=true;
            }
        }
        
        return vis;
        
    }
};