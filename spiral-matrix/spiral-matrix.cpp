class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        
        vector<int> v;
        
        while(up<=down&&left<=right)
        {
            int i = 0;
            int j= 0;
            for(j=left;j<=right;j++)
            {
                v.push_back(matrix[up][j]);
            }
            up++;
            
            
            for(i=up;i<=down;i++)
            {
                v.push_back(matrix[i][right]); 
            }
            right--;
            
            if(up<=down)
            {
                for(j=right;j>=left;j--)
                {
                    v.push_back(matrix[down][j]); 
                }
                down--;
            }
            
            if(left<=right)
            {
                for(i=down;i>=up;i--)
                {
                    v.push_back(matrix[i][left]); 
                }
                left++;
            }
            
        }
        
        return v;
        
        
    }
};