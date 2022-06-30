long long int cnt = 0;

class Solution {
public:
    
    void dfs(int src,vector<bool> &vis,vector<int> adj[])
    {
        vis[src] = true;
        cnt++;
        for(auto x:adj[src])
        {
            if(!vis[x])
                dfs(x,vis,adj);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        
        for(auto x:edges)
        {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        long long int ans = n;
        ans = (ans*(ans-1))/2;
        for(int i = 0 ;i<n;i++)
        {
            if(!vis[i])
            {
                cnt = 0;
                dfs(i,vis,adj);
                ans-=((cnt)*(cnt-1))/2;
            }
        }
        return ans;
        
    }
};