class Solution {
public:
    int maxPower(string s) {
        char prev = s[0];
        
        int mx = 0;
        int cnt = 0;
        for(auto x:s)
        {
            if(x==prev)
            {
                cnt++;
            }
            else
                
            {
                cnt = 1;
            }
            mx= max(cnt,mx);
            prev = x;
        }
        return mx;
    }
};