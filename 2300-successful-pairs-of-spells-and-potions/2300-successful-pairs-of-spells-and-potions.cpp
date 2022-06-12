class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> v;
        int m = potions.size();
        int mn = *min_element(potions.begin(),potions.end());
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++)
        {
            long long x = spells[i];
            int cnt = 0;
            
            int l = 0;int u = m-1;
            int res = m;
            while(l<=u)
            {
                int mid = (l+u)/2;
                
                if(1LL*x*potions[mid]>=success)
                {
                    res = mid;
                    u = mid-1;
                }
                else
                    l = mid+1;
            }
            
            cnt = m-res;
            v.push_back(cnt);
        }
        return v;
    }
};