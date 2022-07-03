class Solution {
public:
    unordered_map<int,int> closePos;
    
    string solve(string s,int l,int r)
    {
        string ans = "";
        int n = 0;
        while(l<=r)
        {
            if(s[l]>='0'&&s[l]<='9')
            {
                n=n*10+s[l]-'0';
            }
            else if(s[l]=='[')
            {
                string sub = solve(s,l+1,closePos[l]-1);
                
                while(n!=0)
                {
                    ans+=sub;
                    n--;
                }
                l = closePos[l];
            }else if(s[l]==']')
            {
                l++;
                continue;
            }
            else
            {
                ans+=s[l];
            }
            l++;
        }
        return ans;
    }
    
    string decodeString(string s) {
        int n = s.size();
        stack<int> stk;
        for(int i  = 0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                stk.push(i);
            }
            else if(s[i]==']')
            {
                closePos[stk.top()]=i;
                stk.pop();
            }
        }
        
        return solve(s,0,n-1);
    }
    
    
};