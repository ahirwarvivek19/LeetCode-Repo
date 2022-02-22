class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for(int i=0;i<s.size();i++)
        {
            int temp = s[i]-'A'+1;
            
            num = num*26+temp;
        }
        return num;
    }
};