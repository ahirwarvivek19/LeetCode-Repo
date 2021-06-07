class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        int f=0;
        int s=0;
        int t=0;
        
        for(auto x: firstWord)
        {
            f=f*10+(x-'a');
 
        }

        
        for(auto x: secondWord)
        {
            s=s*10+(x-'a');
 
        }
      
        for(auto x: targetWord)
        {
            t=t*10+(x-'a');
       
        }
        
        if(t==(f+s))
        {
            return true;
        }
        return false;
    }
};