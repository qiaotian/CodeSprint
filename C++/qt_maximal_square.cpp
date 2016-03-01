// 1st solution (12ms, beats 24%)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows?matrix[0].size():0;
        
        int maxsize = 0;
        vector<vector<int>> distri(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                // 边界条件
                if(i == 0 || j == 0) {
                    distri[i][j] = matrix[i][j]-'0';
                    maxsize = max(maxsize, distri[i][j]);
                    continue;
                }
                // 非边界部分
                if(matrix[i][j] == '1') {
                    distri[i][j] = min(distri[i-1][j-1], min(distri[i-1][j], distri[i][j-1])) + 1;
                    maxsize = max(maxsize, distri[i][j]);
                }
            }
        }
        return maxsize*maxsize;
    }
};

// 2nd solution 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int maxsize = 0, pre = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= m; i++) {
                // 列优先 and 1-based address
                // 第0行置零
                int temp = dp[i];
                if (matrix[i - 1][j] == '1') {
                    // the old dp[i] stores the maxsize of the node left to the new dp[i]
                    // the old dp[i-1] stores the maxsize of the node upper the new dp[i]
                    // the pre store the maxsize of the top-left node
                    dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                    maxsize = max(maxsize, dp[i]);
                }
                else dp[i] = 0; 
                pre = temp; // point pre to current node, which is the 
            }
        }
        return maxsize * maxsize;
    }
};

/**
 * 1st solution is easy to understand
 * 2st solution use less memory
 *     optimize space complexity: N*N --> N*2 --> N*1
 * 
 * REFERENCE
 * https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
 * /
