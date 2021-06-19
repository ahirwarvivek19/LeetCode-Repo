class Solution {
public:
    bool divisorGame(int n) {
//         // bob = false
//         // Alice = true
//         bool ans = true;
//         bool bad = 0;
//         for(int i=1;i<=15;i+=2)
//         {
//             bad |= (n==(1<<i));
//         }
        
//         return bad| n%2 ? false:true;
        return n%2==0;
    }
};