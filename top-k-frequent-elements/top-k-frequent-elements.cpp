class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto x: nums)
        {
            mp[x]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto x : mp){
            pq.push(make_pair(x.second, x.first));
        }
        for(int i=0;i<k;i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
        
    }
};