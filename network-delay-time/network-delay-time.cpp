class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<pair<int,int>>> mp;
        vector<int> dist(n+1,INT_MAX);
        for(auto t: times)
        {
            mp[t[0]].push_back({t[1],t[2]});
            // dist[t[0]]= INT_MAX;
        }
        
        set<pair<int,int>> s;
        
        
        dist[k]=0;
        s.insert({0,k});
        
        while(!s.empty())
        {
            auto p = *s.begin();
            int node = p.second;
            int nodeDist = p.first;
            
            s.erase(s.begin());
            
            for(auto nbr: mp[node])
            {
                int dest = nbr.first;
                if(nodeDist+nbr.second<dist[dest])
                {
                    auto f = s.find({dist[dest],dest});
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    
                    dist[dest]=nodeDist+nbr.second;
                    s.insert({dist[dest],dest});
                }
            }
        }
        
        int maxe =INT_MIN;
        
        for(int i=1;i<=n;i++)
        {
            maxe = max(maxe,dist[i]);
        }
        
        if(maxe==INT_MAX)
            return -1;
        return maxe;
    }
};