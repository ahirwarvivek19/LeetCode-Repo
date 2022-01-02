class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        int n = time.size();
        vector<int> mp(70,0);
        for(int i=0;i<n;i++)
        {
            if(time[i]==0||time[i]%60==0)
            {
                cnt+=mp[0];
            }
            else
            {
                cnt+=(mp[60-time[i]%60]);
            }
            mp[time[i]%60]++;
        }
        return cnt;
    }
};