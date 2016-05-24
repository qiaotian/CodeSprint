/**
 * DFS
 * 遍历每个节点，如果找到“岛屿”的一角，基于该店使用DFS将“岛屿”的
 * 全部土地置为“海洋”。这样无需使用额外内存来标记是否已被访问过。
 */
class Solution {
private:
    void DFS(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';

        if(row>0 && grid[row-1][col]=='1')
            DFS(grid, row-1, col);
        if(col>0 && grid[row][col-1]=='1')
            DFS(grid, row, col-1);
        if(row<grid.size()-1 && grid[row+1][col]=='1')
            DFS(grid, row+1, col);
        if(col<grid[0].size()-1 && grid[row][col+1]=='1')
            DFS(grid, row, col+1);
    }
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;

        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]=='1') {
                    ans++;
                    DFS(grid, i, j);
                }
            }
        }
        return ans;
    }
};

/**
 * BFS
 * 遍历每个节点，如果找到“岛屿”的一角，基于该店使用BFS将“岛屿”的
 * 全部土地置为“海洋”。这样无需使用额外内存来标记是否已被访问过。
 */
//略
