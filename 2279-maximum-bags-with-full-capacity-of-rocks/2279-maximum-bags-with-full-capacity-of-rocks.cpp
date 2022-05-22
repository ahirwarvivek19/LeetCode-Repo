class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int r) {
        int n = rocks.size();
        int cnt = 0;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            v[i] = capacity[i]-rocks[i];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
            if(v[i]==0)
            {
                cnt++;
            }
            else
            {
                if(r>=v[i])
                {
                    r-=v[i];
                    cnt++;
                    v[i] = 0;
                    
                }
            }
        }
        return cnt;
    }
};