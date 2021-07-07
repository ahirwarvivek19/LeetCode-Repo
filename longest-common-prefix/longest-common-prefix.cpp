class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        for(int i=0; ; i++)
        {
            for(auto& s : strs)
            {
                if(i >= s.size() || s[i] != strs[0][i])
                    return strs[0].substr(0,i);
            }
        }
        
        return "";
    }
};