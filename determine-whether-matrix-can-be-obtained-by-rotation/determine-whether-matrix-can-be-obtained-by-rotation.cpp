class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> tmp = mat;
        for(int z=0;z<4;z++)
        {
            for(int row = 0;row<n;row++)
            {
                int c = n-1-row;
                for(int col = 0;col<n;col++)
                {
                    int r = col;
                    tmp[r][c]=mat[row][col];
                }
            }
            mat=tmp;
            if(mat==target)
                return true;
        }
        
        
        
        return false;
    }
};