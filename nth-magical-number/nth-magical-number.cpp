#define mod 1000000007
class Solution {
private:
    long long int LCM(long long int a, long long int b)
    {
        return ((long long)a * b*1ll) / __gcd(a, b);
    }
    int f(long long int n, long long int a, long long int b) {
        if(a>b)
            swap(a,b);
        long long int low = 1;
        long long int high = n*a*1ll;
        
        long long int ans = high;
        long long int lcm = LCM(a,b);
        
        while(low<=high)
        {
            long long int mid = ((high+low)>>1);
            long long int cnt = (mid/a)+(mid/b)-(mid/lcm);
            if(cnt>=n)
            {
                ans = mid;
                high = mid-1;
            }
            else 
            {
                low = mid+1;
                // ans = mid;
            }
            
        }
        return ans%mod;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        return f(n,a,b);
    }
};