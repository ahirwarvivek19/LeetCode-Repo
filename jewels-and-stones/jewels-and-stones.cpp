class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,bool> mp;
        for(auto x: jewels)
        {
            mp[x]=true;
        }
        int cnt=0;
        for(auto x:  stones)
        {
            if(mp[x]==true)
            {
                cnt++;
            }
        }
        
        return cnt;
        
    }
};