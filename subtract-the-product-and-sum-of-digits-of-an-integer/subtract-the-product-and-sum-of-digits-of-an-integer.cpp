class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1,sum=0;
        if(n==0)
            return 0;
        while(n>0)
        {
            int dig = n%10;
            prod = prod*dig;
            sum = sum+dig;
            n/=10;
        }
        return prod-sum;
    }
};