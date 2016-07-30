/**
* @Author: Tian Qiao
* @Date:   2016-07-29T01:07:27+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-29T01:07:35+08:00
* @Inc: Google
* @Difficulty: Hard
*/

/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
*/

// 300ms beats 21%, bad
class Solution {
private:
    vector<vector<int>> dist;
    vector<vector<int>> home; // grid[i][j]被dfs的次数
    vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

    // 返回已访问0元素个数
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        queue<pair<int, int>> que;
        for(auto dir:dirs) {
            int r = i+dir.first;
            int c = j+dir.second;
            if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==0 && !flag[r][c]) {
                que.push({r,c});
                flag[r][c] = true;
            }
        }
        int layer = 0;
        while(!que.empty()) {
            int cnt = que.size();
            for(int i=0; i<cnt; i++) {
                pair<int, int> pos = que.front();
                que.pop();
                dist[pos.first][pos.second] += (layer+1);
                home[pos.first][pos.second]++;
                for(auto dir:dirs) {
                    int r = pos.first+dir.first;
                    int c = pos.second+dir.second;
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==0 && !flag[r][c]) {
                        que.push({r, c});
                        flag[r][c] = true;
                    }
                }
            }
            layer++;
        }
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int ans = INT32_MAX;
        int m = grid.size();
        int n = m==0?0:grid[0].size();

        dist.resize(m, vector<int>(n, 0));
        home.resize(m, vector<int>(n, 0));

        // 统计房子数
        int ones = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ones+=grid[i][j]==1;
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) dfs(grid, i, j);
                else if(grid[i][j]==2) dist[i][j] = INT32_MAX;
                else continue;
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0 && home[i][j]==ones) ans = min(ans, dist[i][j]);
            }
        }

        return ans==INT32_MAX?-1:ans; //
    }
};
// 注意：
// 1.防止元素重复入队
// 2.留意特殊情况,eg [[1]], [[1,2,0]]
// 3.要保证[i,j]元素到所有1均可达，就要统计每个0被1访问的次数

// https://discuss.leetcode.com/topic/31702/36-ms-c-solution
// DFS用于矩阵中，往往需要标记是否已经访问（树结构中则不需要，因为树的层次结构可以避免重复访问）
// 本方法针对此做了优化，不用另外开辟空间存储是否以经访问，并不断更新
// 以下方法将第一栋访问所有值为0的单元，然后将0置为-1；
// 第二栋则只访问值为-1的单元格，依次类推
class Solution {
public:
    int shortestDistance(vector<vector<int>> grid) {
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    mindist = -1;
                    auto dist = grid;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (q.size()) {
                        auto ij = q.front();
                        q.pop();
                        for (int d=0; d<4; ++d) {
                            int i = ij.first + delta[d];
                            int j = ij.second + delta[d+1];
                            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                                grid[i][j]--;
                                dist[i][j] = dist[ij.first][ij.second] + 1;
                                total[i][j] += dist[i][j] - 1;
                                q.emplace(i, j);
                                if (mindist < 0 || mindist > total[i][j])
                                    mindist = total[i][j];
                            }
                        }
                    }
                    walk--;
                }
            }
        }
        return mindist;
    }
};
