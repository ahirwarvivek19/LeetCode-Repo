// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int res = 1;
        int l=  0;
        int r= n;
        int mid = (l+r)/2;
        while(l<=r)
        {
            mid = (l+(r-l)/2);
            
            if(isBadVersion(mid))
            {
                res=  mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return res;
        
        
    }
};