class Solution {
public:

    vector<bool> columns;
    vector<bool> main_diagonal;
    vector<bool> semi_diagonal;

    void dfs(vector<int>& chess, int row, int& res) {
        int n = chess.size();
        if(row == n) {
            res++;
            return;
        }
        for(int col = 0; col < n; col++) {
            if(!(columns[col] && main_diagonal[n-row+col+1] && semi_diagonal[row+col])) continue; //剪枝

            chess[row] = col;
            columns[col] = main_diagonal[n-row+col+1] = semi_diagonal[row+col] = false;
            dfs(chess, row+1, res);
            columns[col] = main_diagonal[n-row+col+1] = semi_diagonal[row+col] = true;
        }
    }

    int totalNQueens(int n) {
        int res = 0;

        vector<int> chess(n, -1);
        this->columns = vector<bool>(n, true);
        this->main_diagonal = vector<bool>(2*n-1, true);
        this->semi_diagonal = vector<bool>(2*n-1, true);

        dfs(chess, 0, res);

        return res;
    }
};
