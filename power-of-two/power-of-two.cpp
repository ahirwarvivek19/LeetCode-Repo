class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        {
            return false;
        }
        int temp = abs(n);
        
        return (temp&(temp-1))==0;
        
    }
};