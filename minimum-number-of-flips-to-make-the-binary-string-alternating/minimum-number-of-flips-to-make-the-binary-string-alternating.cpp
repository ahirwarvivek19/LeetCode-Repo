class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++)
        {
            int j = i%n;
            v[i]=(i%2)^(s[j]-'0');
        }

        vector<int> cnt(2,0);
        
        for(int i=0;i<n;i++)
        {
            cnt[v[i]]++;
        }
        int l=0,r=n;
        int ans = n;
        while(r<2*n)
        {
            // int tmp = n-max(cnt[0],cnt[1]);
            int tmp = min(cnt[0],cnt[1]);
            ans = min(ans,tmp);
            cnt[v[l++]]--;
            cnt[v[r++]]++;
        }
        return ans;
        
    }
};