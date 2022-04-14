class Solution {
public:
    int mySqrt(int x) {
        long long s = 0;
        long long e = x;
        int ans = 0;
        while(s<=e){             
            long long mid = s+(e-s)/2;
            if(mid*mid == x) 
                return mid;     
            else if(mid*mid<x)
            {             
                s = mid+1;
                ans = mid;
            }
            else e=mid-1; 
        }
        return ans;
    }
};