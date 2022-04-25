class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> s;
        
        int n = circles.size();
        
        for(int i=0;i<n;i++)
        {
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];
            
            for(int i=x-r;i<=x+r;i++)
            {
                for(int j= y-r;j<=y+r;j++)
                {
                    int dis = (i-x)*(i-x)+(j-y)*(j-y);
                    if(dis<=r*r)
                    {
                        s.insert({i,j});
                    }
                }
            }
        }
        return s.size();
    }
};