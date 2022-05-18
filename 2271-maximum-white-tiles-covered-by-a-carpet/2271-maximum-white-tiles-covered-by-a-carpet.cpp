class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        
        int n = tiles.size();
        
        int pres[n+1],en[n];
        
        pres[0] = 0;
        
        // en[0] = tiles[0][1];
        
        for(int i=0;i<n;i++)
        {
            pres[i+1] = pres[i]+tiles[i][1]-tiles[i][0]+1;
            en[i] = tiles[i][1];
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int start = tiles[i][0];
            int end = start + carpetLen-1;
            
            int idx = upper_bound(en,en+n,end) - en;
            
            int tsum = pres[idx] - pres[i];

            // now add tiles between end and indx covered by carpet
            if (idx < n and end >= tiles[idx][0]) tsum += end - tiles[idx][0] + 1;

            ans = max(ans,tsum);
        }
        return ans;
    }
};