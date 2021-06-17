class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int mp[26]={0};
        
        for(auto x: sentence)
        {
            mp[x-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(mp[i]<1)
                return false;
        }
        return true;
    }
};