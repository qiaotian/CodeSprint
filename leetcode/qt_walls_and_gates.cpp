/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-05T22:37:41+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-05T23:16:01+08:00
* @Inc: Google, Facebook
* @Difficulty: Medium
*/



_______________________________________________________________________________

You are given a m x n 2D grid initialized with these three possible values.

-1  - A wall or an obstacle.
0   - A gate.
INF - Infinity means an empty room.

We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

_______________________________________________________________________________


class Solution {
public:
    vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    queue<pair<int, int>> que;

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = m?rooms[0].size():0;

        vector<vector<bool>> flags(m, vector<bool>(n, false)); // visited or not
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(rooms[i][j]==0) {
                    que.push({i,j});
                    flags[i][j] = true;
                }
            }
        }
        int layer = 1; //初始化最近距离为1
        while(!que.empty()) {
            int k = que.size();
            for(int i=0; i<k; i++) {
                pair<int, int> pos = que.front();
                que.pop();
                for(auto j:directions) {
                    int r = pos.first+j.first; // row number
                    int c = pos.second+j.second; // col number
                    if(r>=0 && r<m && c>=0 && c<n &&\
                       !flags[r][c] && rooms[r][c]==INT32_MAX) {
                        rooms[r][c] = layer;
                        flags[r][c] = true;
                        que.push({r,c});
                    }
                }
            }
            layer++;
        }
    }
};
