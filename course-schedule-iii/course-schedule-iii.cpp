class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), comp);
        
        // Priority Queue  in MAX HEAP ORDER
        priority_queue<int> pq;
        int sum=0;
        for(auto x: courses)
        {
            int d = x[0];
            int ld = x[1];
            pq.push(d);
            sum+=d;
            
            if(sum>ld)
            {
                sum-=pq.top();
                pq.pop();
            }
            
        }
         return pq.size();
        
    }
};