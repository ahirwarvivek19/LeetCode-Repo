class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                continue;
            }
            else
            {
                
                reverse(s.begin()+l,s.begin()+i);
                l=i+1;
            }
            
        }
        reverse(s.begin()+l,s.end());
        return s;
    }
};