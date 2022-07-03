class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1;
        for(auto x: s)
        {
            if(x=='#')
            {
                if(!s1.empty())
                {
                    s1.pop_back();
                }
            }
            else
            {
                s1.push_back(x);
            }
        }
        
        string t1;
        for(auto x: t)
        {
            if(x=='#')
            {
                if(!t1.empty())
                {
                    t1.pop_back();
                }
            }
            else
            {
                t1.push_back(x);
            }
        }
        
        return s1==t1;
    }
};