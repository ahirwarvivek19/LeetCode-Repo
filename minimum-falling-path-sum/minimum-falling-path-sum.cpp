class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        int m=A[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0)                                                    //Leftmost or first column
                A[i][j]+=min(A[i-1][j],A[i-1][j+1]);
                else if(j==m-1)A[i][j]+=min(A[i-1][j],A[i-1][j-1]);     //Rightmost or last column
                else A[i][j]+=std::min({A[i-1][j],A[i-1][j+1],A[i-1][j-1]}); //Remaining cases
            }
        }
        int sum=INT_MAX;
        for(int i=0;i<m;i++){
            sum=min(sum,A[n-1][i]);                                      //Last row scan
        }
        return sum;
    }
};