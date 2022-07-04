class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> lc(n,1);
        
        for(int i = 1;i<n;i++)
        {
            if(a[i]>a[i-1])
            {
                lc[i] = lc[i-1]+1;
            }
        }
        
        vector<int> rc(n,1);
        
        for(int i = n-2;i>=0;i--)
        {
            if(a[i]>a[i+1])
            {
                rc[i] = rc[i+1]+1;
            }
        }
        int cnt  = 0;
        for(int i = 0 ; i <n;i++)
        {
            cnt+=max(lc[i],rc[i]);
        }
        return cnt;
    }
};