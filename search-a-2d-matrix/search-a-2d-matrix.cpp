class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int n = matrix.size();
        int m = matrix[0].size();
        int j=m-1;
        
        while(i>=0 && i<n && j>=0 && j<m)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
            else if(matrix[i][j]<target)
                i++;
        }
        
        return false;
    }
};