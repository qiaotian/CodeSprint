class Solution {
private:
    vector<vector<string>> res;
    vector<string> matrix;
    vector<bool> columns; // 列
    vector<bool> main_diagonal; // 主对角线
    vector<bool> semi_diagonal; // 副对角线

    void dfs(vector<int>& chess, int row, vector<string>& matrix) {
        int n = columns.size();
        if(row == n) {
            res.push_back(matrix);
            return;
        }
        for(int i = 0; i < n; i++) {
            // 检查第row行第i位是否可用
            if(columns[i] && main_diagonal[n-row+i-1] && semi_diagonal[row+i]){
                chess[row] = i;
                matrix[row][i] = 'Q';
                // mark flag
                columns[i] = main_diagonal[n-row+i-1] = semi_diagonal[i+row] = false;
                dfs(chess, row+1, matrix);
                // recover
                columns[i] = main_diagonal[n-row+i-1] = semi_diagonal[i+row] = true;
                matrix[row][i] = '.';
            } else {
                continue;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->columns = vector<bool>(n, true);
        this->matrix = vector<string>(n, string(n, '.'));
        this->main_diagonal = vector<bool>(2*n-1, true);
        this->semi_diagonal = vector<bool>(2*n-1, true);

        vector<int> chess(n, -1);
        dfs(chess, 0, matrix);
        return res;
    }
};
