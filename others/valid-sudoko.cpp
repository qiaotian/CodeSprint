class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used1[9][9] = {false}, used2[9][9] = {false}, used3[9][9] = {false};

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] != '.')
                {
                    int digit = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3; //
                    if(used1[i][digit] || used2[j][digit] || used3[k][digit])
                        return false;
                    used1[i][digit] = used2[j][digit] = used3[k][digit] = true;
                }
            }
        }
        return true;
    }
};

/***
 * There are just 3 rules to Sudoku:
 * 1. Each row must have the numbers 1-9 occuring just once.
 * 2. Each column must have the numbers 1-9 occuring just once.
 * 3. And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
 */
