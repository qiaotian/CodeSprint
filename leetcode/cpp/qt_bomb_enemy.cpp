/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:01:45+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:01:47+08:00
* @Difficulty: Medium
* @Tag: DP
* @Inc: Google
*/

/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
*/

class Solution {
public:
/*
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> horizon(rows, vector<int>(cols, 0));
        vector<vector<int>> vertical(rows, vector<int>(cols, 0));

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]=='E') horizon[i][j] = (j==0?1:horizon[i][j-1]+1);
                if(grid[i][j]=='W') horizon[i][j] = 0;
                if(grid[i][j]=='0') horizon[i][j] = (j==0?0:horizon[i][j-1]);
            }
            for(int j=cols-2; j>=0; j--) {
                if(grid[i][j]=='E') horizon[i][j] = max(horizon[i][j], horizon[i][j+1]);
                if(grid[i][j]=='W') horizon[i][j] = 0;
                if(grid[i][j]=='0') horizon[i][j] = max(horizon[i][j], horizon[i][j+1]);
            }
        }

        for(int j=0; j<cols; j++) {
            for(int i=0; i<rows; i++) {
                if(grid[i][j]=='E') vertical[i][j] = (i==0?1:vertical[i-1][j]+1);
                if(grid[i][j]=='W') vertical[i][j] = 0;
                if(grid[i][j]=='0') vertical[i][j] = (i==0?0:vertical[i-1][j]);;
            }
            for(int i=rows-2; i>=0; i--) {
                if(grid[i][j]=='E') vertical[i][j] = max(vertical[i][j], vertical[i+1][j]);
                if(grid[i][j]=='W') vertical[i][j] = 0;
                if(grid[i][j]=='0') vertical[i][j] = max(vertical[i][j], vertical[i+1][j]);
            }
        }

        int ans = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                //if(grid[i][j]=='E') ans = max(ans, horizon[i][j]+vertical[i][j]-1);
                //if(grid[i][j]=='W') continue;
                if(grid[i][j]=='0') ans = max(ans, horizon[i][j]+vertical[i][j]);
            }
        }
        return ans;
    }
*/
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int ans = 0;

        int m = grid.size();
        int n = m?grid[0].size():0;

        int rowhits, colhits[n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!j || grid[i][j-1] == 'W') {
                    rowhits = 0;
                    for (int k=j; k<n && grid[i][k] != 'W'; k++)
                        rowhits += grid[i][k] == 'E';
                }
                if (!i || grid[i-1][j] == 'W') {
                    colhits[j] = 0;
                    for (int k=i; k<m && grid[k][j] != 'W'; k++)
                        colhits[j] += grid[k][j] == 'E';
                }
                if (grid[i][j] == '0')
                    ans = max(ans, rowhits + colhits[j]);
            }
        }
        return ans;
    }
};
