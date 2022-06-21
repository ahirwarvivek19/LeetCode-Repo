class Solution {
public:
    int furthestBuilding(vector<int>& a, int bricks, int ladders) {
        int n = a.size();
        int i = 0;
        priority_queue<int> pq;
        for(i=0;i<n-1;i++)
        {
            int diff = a[i+1]-a[i];
            if(diff<=0)
                continue;
            
            pq.push(diff);
            bricks-=diff;
            
            if(bricks<0)
            {
                bricks+=pq.top();
                pq.pop();
                ladders--;
            }
            if(ladders<0)
                break;
            
            
        }
        
        return i;
    }
};