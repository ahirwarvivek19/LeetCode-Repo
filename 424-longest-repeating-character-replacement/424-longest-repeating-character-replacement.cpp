class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int res= 0 ;
        int maxf=0;
        for(int i = 0 ;i<s.size();i++)
        {
            mp[s[i]]++;
            maxf = max(maxf,mp[s[i]]);
            if(res-maxf<k)
            {
                res++;
            }
            else
            {
                mp[s[i-res]]--;
            }
        }
        return res;
    }
};