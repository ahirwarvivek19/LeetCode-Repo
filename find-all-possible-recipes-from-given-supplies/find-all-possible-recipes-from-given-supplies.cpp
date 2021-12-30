class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        int n = recipes.size();
        unordered_set<string> s;
        for(auto x:supplies)
        {
            s.insert(x);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        bool vis[n];
        memset(vis,false,sizeof(vis));
        
        bool cc = true;
        while(cc)
        {
            cc = false;
            queue<int> sq;
            while(!q.empty())
            {
                bool flag = true;
                int ind = q.front();
                q.pop();
                int m = ingredients[ind].size();
                for(int j=0;j<m;j++)
                {
                    if(s.find(ingredients[ind][j])==s.end())
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag==true)
                {
                    cc = true;
                    // res.push_back(recipes[ind]);
                    s.insert(recipes[ind]);
                    vis[ind] = true;
                }
                else
                {
                    sq.push(ind);
                }
            }
            q=sq;
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i])
            {
                res.push_back(recipes[i]);
            }
        }
        
        return res;
        
    }
};