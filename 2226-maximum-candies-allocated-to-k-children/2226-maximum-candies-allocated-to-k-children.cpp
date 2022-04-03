class Solution {
public:
    
    // int check(vector<int> &candies,int mid)
    // {
    //     int cnt = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         cnt+=candies[i]/mid;
    //     }
    //     return cnt;
    // }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long n = candies.size();
        
        long long mx = *max_element(candies.begin(),candies.end());
        
        long long  l = 1;
        long long r = mx;
        int res=0;
        while(l<=r)
        {
            long long mid = (r-l)/2+l;
            long long cnt = 0;
            for(int i=0;i<n;i++)
            {
                cnt+=candies[i]/mid;
            }
            
            if(cnt>=k)
            {
                l = mid+1;
                res = mid;
            }
            else
            {
                r=mid-1;
            }
            
            
        }
        return res;
        
    }
};