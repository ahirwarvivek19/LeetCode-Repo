class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int mx = 0;
        sort(special.begin(),special.end());
        for(int i=0;i<special.size();i++)
        {
            int z = special[i] - bottom;
            cout<<z<<" ";
            bottom = special[i]+1;
            mx = max(z,mx);
        }
        mx = max(mx,top-bottom+1);
        return mx;
    }
};