class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int count = 0;
                for (int ii=max(i-1, 0); ii<min(i+2, m); ++ii) //
                    for (int jj=max(j-1, 0); jj<min(j+2, n); ++jj) //
                        count += board[ii][jj] & 1;
                if (count == 3 || count - board[i][j] == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] >>= 1;
    }
};

/**
 * Idea: use more bits to keep more information.
 * 
 * Originally, board use only one bit 1 or 0 to represent live or dead, while we can
 * use 1X or 0X to represent both previous state and current state, where the first bit 
 * represent the new state of life, and the second bit represents the previous state of life.
 * /
