class Solution {
public:
    string getHint(string secret, string guess) {
        int mp1[10]={0},mp2[10]={0};
        
        int bull = 0;
        int i = 0;
        for(auto x:secret)
        {
            // mp[x]++;
            if(x==guess[i])
                bull++;
            else
            {
                mp1[x-'0']++;
                mp2[guess[i]-'0']++;
            }
            i++;
        }
        int c = 0;
        for(int i= 0;i<10;i++)
        {
            c+=min(mp1[i],mp2[i]);
        }
        // c = c-bull;
        
        string s = to_string(bull)+"A"+to_string(c)+"B";
        return s;
        
    }
};