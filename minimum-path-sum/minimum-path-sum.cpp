class Solution {
private:
    vector<vector<int>> memo;
    int minSum(vector<vector<int>> &grid, int i, int j){
        if(i >= grid.size() || j >= grid.at(i).size()) return INT_MAX;
        if(i == grid.size() - 1 && j == grid.at(i).size() - 1)
            return grid.at(i).at(j);
        
        if(memo.at(i).at(j) != -1) return memo.at(i).at(j);
        
        int right = minSum(grid, i, j + 1);
        int down  = minSum(grid, i + 1, j);
        
        return memo.at(i).at(j) = min(right, down) + grid.at(i).at(j);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        // memo = vector<vector<int>>(grid.size(), vector<int>(grid.at(0).size(), -1));
        // return minSum(grid, 0, 0);
        
         //Fast I/O in C++
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid.size();
        if(rows==0)
            return 0;
        int cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int i,j;
        
        dp[0][0] = grid[0][0];  //1st element is starting point
        //Fill 1st row
        for(i=1;i<cols;++i)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        
        //Fill 1st Col
        for(i=1;i<rows;++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        
        //Now fill the rest of the cell
        for(i=1;i<rows;++i)
        {
            for(j=1;j<cols;++j)
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
        return dp[rows-1][cols-1];
    }
};