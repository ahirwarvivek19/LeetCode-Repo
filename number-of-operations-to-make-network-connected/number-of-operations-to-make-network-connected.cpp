class Solution {
public:
    
    void dfs(int src, vector<bool> &vis, vector<vector<int>>& adj)
    {
        vis[src]=true;
        for(auto nbr: adj[src])
        {
            if(!vis[nbr])
            {
                dfs(nbr,vis,adj);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1)
        {
            return -1;
        }
        
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(auto x: connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt-1;
        
    }
};