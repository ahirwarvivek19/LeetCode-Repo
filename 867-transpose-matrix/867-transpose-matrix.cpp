class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> t(m,vector<int> (n));
        
        for(int j=0;j<m;j++)
        {
            for(int i = 0;i<n;i++)
            {
                t[j][i] =  mat[i][j];
            }
        }
        return t;
    }
};