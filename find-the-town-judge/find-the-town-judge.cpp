class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> par(n+1,0);
        vector<int> cnt(n+1,0);
        
        for(auto x:trust)
        {
            cnt[x[0]]--;
            cnt[x[1]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};