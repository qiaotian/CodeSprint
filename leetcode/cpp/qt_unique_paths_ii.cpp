/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T17:06:14+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T18:47:08+08:00
*/



/*
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
*/

// TLE, 对于矩阵使用DFS，很容导致超时，一般优先考虑动归
/*
class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int i, int j) {
        int ans = 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(i==m-1 && j==n-1) return 1;

        if(obstacleGrid[i][j]==1) return 0;

        int down = i==m-1?0:helper(obstacleGrid, i+1, j);
        int right = j==n-1?0:helper(obstacleGrid, i, j+1);

        return down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.empty()?0:obstacleGrid[0].size();

        if(m==0 || n==0) return 0;

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;

        return helper(obstacleGrid, 0, 0);
    }
};*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.empty()?0:obstacleGrid[0].size();

        if(m==0 || n==0) return 0;
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;

        vector<vector<int>> steps(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) steps[i][j] = 1;
                else if(i==0 && j!=0) steps[i][j] = obstacleGrid[i][j]==1?0:steps[i][j-1];
                else if(i!=0 && j==0) steps[i][j] = obstacleGrid[i][j]==1?0:steps[i-1][j];
                else steps[i][j] = obstacleGrid[i][j]==1?0:(steps[i-1][j]+steps[i][j-1]);
            }
        }
        return steps[m-1][n-1];
    }
};
