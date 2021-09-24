class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int mx=0;
        int len=0;
        for(int i=0;i<s.length();i++)
        {   len=0;
            map<char,int>mp;
            for(int j=i;j<s.length(); j++)
            {
                if(mp[s[j]]==1)break;

                mp[s[j]]++;
                len++;
            }
            mx = max(len,mx);
        }
        return mx;
        
    }
};