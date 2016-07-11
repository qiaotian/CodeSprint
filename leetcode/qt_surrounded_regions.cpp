/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-11T20:58:51+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T00:26:03+08:00
*/

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool bfs(vector<vector<char>>& board,\
             vector<vector<bool>>& visited,\
             vector<pair<int, int>>& vec, int i, int j) {

        bool isSurrounded = true;
        queue<pair<int, int>> que;
        que.push({i, j});
        vec.push_back({i, j});
        //visited[i][j] = true;
        while(!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            for(auto direction : directions) {
                int r = cur.first + direction.first;
                int c = cur.second + direction.second;
                //visited[r][c] = true;
                if(r==0 || r==board.size()-1 || c==0 || c==board[0].size()-1) {
                    if(board[r][c]=='O') isSurrounded = false;
                    continue;
                }
                if(visited[r][c] || board[r][c]=='X') continue; //如果已经访问过或者是‘X’就跳过
                que.push({r, c});
                vec.push_back({r, c});
                visited[r][c] = true;
            }
        }
        return isSurrounded;
    }
    void solve(vector<vector<char>>& board) {
        int m = (int)board.size();
        int n = (int)(board.empty()?0:board[0].size());

        if(m<3 || n<3) return;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> positions; // 一次广搜的所有节点
        for(int i=1; i<m-1; i++) {
            for(int j=1; j<n-1; j++) {
                if(!visited[i][j] && board[i][j]=='O') {
                    bool isSurrounded = bfs(board, visited, positions,i,j);
                    if(isSurrounded) {
                        for(auto pos:positions) board[pos.first][pos.second] = 'X';
                    }
                    positions.clear();
                }
            }
        }
    }
};


int main() {
    vector<vector<char>> board = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    Solution *sln = new Solution();
    sln->solve(board);
    for(auto i:board) {
        for(auto j:i) cout << j;
        cout << endl;
    }
    return 0;
}
