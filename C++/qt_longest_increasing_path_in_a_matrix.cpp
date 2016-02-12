// 1st solution (bad)
/*
class Solution {
public:
    int dps(int i, int j, int rows, int cols, vector<vector<int>>& depth, vector<vector<int>>& mat) {
        
        if(depth[i][j]) return depth[i][j];
        
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(int c = 0; c < directions.size(); c++) {
            int ii = i + directions[c][0];
            int jj = j + directions[c][1];

            if(ii < 0 || ii >= rows || jj < 0 || jj >=cols || mat[ii][jj] <= mat[i][j]) continue;

            depth[i][j] = max(depth[i][j], dps(ii, jj, rows, cols, depth, mat));
        }
        
        return ++depth[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matirx[0].size() == 0) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        int maxlen = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int len = dps(i, j, rows, cols, dp, matrix);
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};
*/

// 2nd solution (better)
class Solution {
private:
    int rows = 0, cols = 0;
    int dps(vector<vector<int>>& matrix, vector<vector<int>>& dp, int top, int len, int x, int y) {
        // matrix:
        // dp: the max depth from current element, initialized with value zero.
        // top: the previous element value to matrix(x, y)
        // len: the length of path with current node excluded
        if(x<0 || x>=rows || y<0 || y>= cols || matrix[x][y]<=top) return len;
        if(dp[x][y]) return len + dp[x][y];
        
        int upper = dps(matrix, dp, matrix[x][y], len+1, x, y-1);
        int lower = dps(matrix, dp, matrix[x][y], len+1, x, y+1);
        int left = dps(matrix, dp, matrix[x][y], len+1, x-1, y);
        int right = dps(matrix, dp, matrix[x][y], len+1, x+1, y);
        
        dp[x][y] = max(max(upper, lower), max(left, right)) - len;
        
        return dp[x][y]+len;
    }
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        
        rows = matrix.size(); cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int len = -2147483648; // 
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                len = max(len, dps(matrix, dp, -2147483648, 0, i, j));
            }
        }
        return len;
    }
};

/**
 * DP and DFS
 * /

