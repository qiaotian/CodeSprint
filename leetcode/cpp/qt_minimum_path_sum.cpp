// TLE for large array
/*
class Solution {
private:
    int helper(vector<vector<int>>& grid, int x, int y) {
        if(x > grid.size()-1 || y > grid[0].size()-1) return INT32_MAX;
        if(x == grid.size()-1 && y == grid[0].size()-1) return grid[x][y];
        
        if(x == grid.size()-1) 
            return grid[x][y] + helper(grid, x, y+1);
        if(y == grid[0].size()-1) 
            return grid[x][y] + helper(grid, x+1, y);
        if(x < grid.size()-1 && y < grid[0].size()-1) 
            return grid[x][y] + min(helper(grid, x+1, y), helper(grid, x, y+1));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return helper(grid, 0, 0);
    }
};
*/

// 2nd solution 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> sum(rows, vector<int>(cols, grid[0][0]));
        for(int i = 1; i < rows; i++) sum[i][0] = sum[i-1][0] + grid[i][0];
        for(int j = 1; j < cols; j++) sum[0][j] = sum[0][j-1] + grid[0][j];
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
            }
        }
        return sum[rows-1][cols-1];
    }
};

/**
 * WARNING
 * The second solution is fast enough, but not space efficiency enough.
 * The space complexity could be optimized.
 * /
