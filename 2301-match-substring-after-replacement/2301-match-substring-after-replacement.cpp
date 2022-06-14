class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<bool>> mp(256,vector<bool>(256,false));
        int n = s.size();
        int m = sub.size();
        
        for(int i = 0;i<256;i++)
        {
            mp[i][i] = true;
        }
        
        for(auto x:mappings)
        {
            mp[x[0]][x[1]] = true;
        }
        
        for(int i = 0 ;i<n-m+1;i++)
        {
            bool flg  = true;
            for(int j = 0;j<m;j++)
            {
                if(!mp[sub[j]][s[i+j]])
                    flg = false;
            }
            if(flg)
                return true;
        }
        return false;
    }
};