/**
* @Author: Tian Qiao
* @Date:   2016-07-20T21:25:15+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-20T21:25:53+08:00
* @Inc: Google
* @Difficulty: Hard
*/

/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/


class Solution {
public:
    const vector<pair<int, int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    int root(int i) {
        while(i!=id[i]) i = id[id[i]]; //path compression
        return i;
    }
    bool find(int p, int q) {
        return root[p]==root[q];
    }
    void union(int p, int q) {
        int i = root[p];
        int j = root[q];
        id[i] = j; // p的parent设置为q
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int count = 0;
        vector<int> ans;
        vector<vector<int>> roi(m, vector<int>(n,0));

        vector<int> id(m*n, 0);
        for(int i=0; i<arr.size(); i++) arr[i] = i;

        for(auto pos:positions) {
            sea[pos.first][pos.second] = 1;
            for(auto d:directions) {
                int r = pos.first+d.first;
                int c = pos.second+d.second;
                if(roi[r][c]==0) continue;
                if(!find(r*n+c, pos.first*n+pos.second)) union(r*n+c, pos.first*n+pos.second);
            }
            ans.push_back();
        }
        return ans;
    }
};

// 新的坐标点具有向旧点聚合的趋势，而非相反
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        roots = vector<int>(m*n, -1);
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int island = 0;
        for (auto pos : positions) {
            int x = pos.first, y = pos.second;
            int idx = x * n + y;
            roots[idx] = idx; // 初始化idx的root为idx
            ++island;
            for (auto dir : dirs) {
                int r = x + dir.first, c = y + dir.second;
                int idx_new = r * n + c;
                if (r >= 0 && r < m && c >= 0 && c < n && roots[idx_new] != -1) {
                    int rootPos = find(idx); // 虽然pos的root初始化为idx, 但是有可以在union过程中改变
                    int rootNew = find(idx_new);
                    if(rootPos != rootNew) {
                        roots[rootPos] = rootNew; // union operation
                        --island;
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }

private:
    vector<int> roots;
    int find(int idx) {
        while(idx != roots[idx]) {
            roots[idx] = roots[roots[idx]] = roots[roots[roots[idx]]]; // path compression makes algo faster
            idx = roots[roots[idx]];
        }
        return idx;
    }
};
