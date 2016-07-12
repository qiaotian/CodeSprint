/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-13T00:37:43+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-13T01:31:29+08:00
*/



/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


// 88ms beats 18% bad
class Solution {
public:
    // i: board上起点的横坐标
    // j: board上起点的纵坐标
    // idx: word中待查找char的index
    vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(vector<vector<char>>& board,\
             vector<vector<bool>>& flag,\
             string word, int i, int j, int idx) {
        if(board[i][j] == word[idx] && !flag[i][j]) {
            if(idx==word.size()-1) return true;
            flag[i][j] = true;
            for(auto direction:directions) {
                int r = direction.first+i;
                int c = direction.second+j;
                if(r<0||r>=board.size()||c<0||c>=board[0].size()) continue;//越界处理
                if(dfs(board, flag, word, r, c, idx+1)) return true;
            }
            flag[i][j] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board.empty()?0:board[0].size();

        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(dfs(board, flag, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};

// 优化
