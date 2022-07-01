class Solution {
public:
    // bool mycomp(pair<int,int> x,pair<int,int> y)
    // {
    //     // if(p)
    // }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> v;
        
        for(auto x: boxTypes)
        {
            v.push_back({x[1],x[0]});
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int cnt  = 0;
        for(int i = 0;i<v.size();i++)
        {
            if(truckSize>=v[i].second)
            {
                cnt+=(v[i].second*v[i].first);
                truckSize-=v[i].second;
            }
            else if(truckSize>0)
            {
                int rem = truckSize;
                cnt+=(v[i].first*truckSize);
                truckSize = 0;
            }
            else
            {
                break;
            }
                
                
        }
        return cnt;
    }
};