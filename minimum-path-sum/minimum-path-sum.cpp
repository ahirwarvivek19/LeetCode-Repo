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
        memo = vector<vector<int>>(grid.size(), vector<int>(grid.at(0).size(), -1));
        return minSum(grid, 0, 0);
    }
};