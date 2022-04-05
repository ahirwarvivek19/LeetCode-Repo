class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int i = 0,j=0;
        int res = 0;
        while(i<n && j<n)
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j++]);
                res = max(res,j-i);
            }
            else
            {
                st.erase(s[i++]);
                
            }
        }
        return res;
    }
};