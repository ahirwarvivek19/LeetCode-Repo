class Solution {
public:
    bool f(int node,int par,vector<vector<int>>& adj,vector<int> &vis,int color)
    {
        vis[node] = color;
        
        for(auto nbr: adj[node])
        {
            if(vis[nbr]==0)
            {    
                bool check =  f(nbr,node,adj,vis,3-color);
                if(!check)
                    return false;
            }
            else if(vis[node]==vis[nbr])
                    return false;
            
        }
        return true;
    }
    bool dfs(int node,int c,vector<int>&vis,vector<int>&col,vector<vector<int>>&adj)
    {
        vis[node]=1;
        col[node]=c;
        for(auto child:adj[node])
        {
            if(vis[child]==0)
            {
                if(dfs(child,c^1,vis,col,adj)==false)
                    return false;
            }
            else if(col[child]==col[node])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,0,vis,col,adj)==false)
                    return false;
            }
        }
        return true;
    }
};