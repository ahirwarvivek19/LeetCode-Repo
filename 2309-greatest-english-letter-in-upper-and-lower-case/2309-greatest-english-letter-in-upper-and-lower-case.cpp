class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> uc(26,false),lc(26,false);
        
        for(auto x:s)
        {
            if(x>='a'&&x<='z')
            {
                lc[x-'a']=true;
            }
            else
            {
                uc[x-'A'] = true;
            }
        }
        
        for(int i = 25 ;i>=0;i--)
        {
            if(lc[i]&&uc[i])
            {
                char c= i +'A';
                string r;
                r.push_back(c);
                return r;
            }
                // return (string)(i+'A');
        }
        return "";
    }
};