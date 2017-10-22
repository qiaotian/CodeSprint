class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;

        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();

        vector<int> left(n, 0); // init the left at the start of a line
        vector<int> right(n, n); // init the right at the end of a line
        vector<int> height(n, 0); // init every height with zero

        for(int i = 0; i < m; i++) { // scan every single line
            int left_most = 0, right_most = n;
            for(int j = 0; j < n; j++) { // scan every single elem in a single line
                // update 'left' and 'height' from left to right
                if(matrix[i][j]=='1') {
                    height[j]++;
                    left[j] = max(left[j], left_most);
                    // right[n-j-1] = min(right[n-j-1], right_most);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    //right[n-j-1] = n;
                    left_most = j+1;
                    //right_most = n-j-1;
                }
                // update 'right' from right to left
                if(matrix[i][n-j-1]=='1') {
                    right[n-j-1] = min(right[n-j-1], right_most);
                } else {
                    right[n-j-1] = n;
                    right_most = n-j-1;
                }
            }

            for(int j = 0; j < n; j++)
                res = max(res, (right[j]-left[j])*height[j]);
        }
        return res;
    }
};
// 注意更新方向
// 以及由此引发的索引变化
