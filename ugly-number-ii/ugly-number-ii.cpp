#define ll long long

class Solution {
public:
    int nthUglyNumber(int n) {
        set<ll>pq;
        pq.insert(1);
        ll ele = 1;
        ll cnt =0;
        while(cnt!=n)
        {
            ele=(*pq.begin());
            pq.erase(ele);
            cnt++;
            
            pq.insert(ele*2);
            pq.insert(ele*3);
            pq.insert(ele*5);
            
                
        }
        // if(n==1)
        //     return 1;
        // pq.pop();
        return  ele ;        
    }
};