class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0) return true;
        queue<int> q;
        int n = arr.size();
        q.push(start);
        
        vector<bool> vis(n,false);
        // arr[start] = -1;
        vis[start] = true;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            
            
            
            int left = i-arr[i];
            if(left>=0&&vis[left]==false)
            {
                if(arr[left]==0)
                {
                    return true;
                }
                // arr[left]=-1;
                vis[left] = true;
                q.push(left);
            }
            
            int right = i+arr[i];
            if(right<n&&vis[right]==false)
            {
                if(arr[right]==0)
                {
                    return true;
                }
                // arr[right] = -1;
                vis[right] = true;
                q.push(right);
            }
            
        }
        return false;
    }
};