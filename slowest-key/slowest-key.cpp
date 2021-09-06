class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        
        map<char,int> mp;
        
        mp[keysPressed[0]] =releaseTimes[0];
        for(int i=1;i<n;i++)
        {
            mp[keysPressed[i]] =max(mp[keysPressed[i]], releaseTimes[i]-releaseTimes[i-1]);
        }
        
        
        char mx = mp.begin()->first;
        
        for(auto x: mp)
        {
            if(mp[mx]<x.second)
            {
                mx = x.first;
            }
            else if(mp[mx]==x.second)
            {
                if(x.first>mx)
                    mx = x.first;
            }
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<mx;
        return mx;
    }
};