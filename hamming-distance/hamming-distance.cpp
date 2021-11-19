class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = x^y;
        
        return __builtin_popcount(res);
    }
};