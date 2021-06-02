class Solution {
public:
    
    bool dfs(int src,vector<bool> &vis,vector<bool> &stk,vector<int> adj[])
    {
        vis[src]=true;
        stk[src]=true;
        
        for(auto nbr:adj[src])
        {
            if(stk[nbr]==true)
                return true;
            else if(!vis[nbr])
            {
                bool cycle_mila = dfs(nbr,vis,stk,adj);
                if(cycle_mila)
                    return true;
            }
        }
        
        stk[src]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(auto x: prerequisites)
        {
            adj[x[0]].push_back(x[1]);
        }
        
        vector<bool> vis(numCourses,false);
        vector<bool> stk(numCourses,false);
        
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,stk,adj))
                {
                    return false;
                }
            }
            
        }
        
        return true;
        
        
    }
};