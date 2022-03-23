class Solution {
public:
    
    int f(int i,int sv)
    {
        if(sv>=i)
        {
            return sv-i;
        }
        if(i%2==0)
        {
            return (f(i/2,sv)+1);
        }
        else
        {
            return (f(i+1,sv)+1);
        }
        
    }
    
    int brokenCalc(int startValue, int target) {
        
        return f(target,startValue);
    }
};