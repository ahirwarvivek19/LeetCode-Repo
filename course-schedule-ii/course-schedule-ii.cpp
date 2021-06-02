class Solution {
public:
     bool dfs(int src,vector<bool> &vis,vector<bool> &stk,vector<int> adj[],list<int> &v)
    {
        vis[src]=true;
        stk[src]=true;
        
        for(auto nbr:adj[src])
        {
            if(stk[nbr]==true)
                return true;
            else if(!vis[nbr])
            {
                bool cycle_mila = dfs(nbr,vis,stk,adj,v);
                if(cycle_mila)
                    return true;
            }
        }
        v.push_front(src);
        stk[src]=false;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
         vector<int> adj[numCourses];
        
        for(auto x: prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        
        vector<bool> vis(numCourses,false);
        vector<bool> stk(numCourses,false);
        
        
        vector<int> order;
        
        list<int> v;
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,stk,adj,v))
                {
                    return order;
                }
            }
            
        }
        
        
        for(auto x: v)
        {
            order.push_back(x);
        }
        return order;
        
        
    }
};