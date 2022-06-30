class Solution {
public:
    int countAsterisks(string s) {
        int flg = false;
        int cnt = 0 ;
        for(auto x:s)
        {
            if(x=='|')
                flg = !flg;
            else if(flg==false&&x=='*')
                cnt++;
            
            
        }
        
        return cnt;
    }
};