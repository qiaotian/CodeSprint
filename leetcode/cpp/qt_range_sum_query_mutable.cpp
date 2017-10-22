/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/


class NumMatrix {
private:
    vector<vector<int>> sumMat;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = m==0?0:matrix[0].size();
        
        sumMat.resize(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                sumMat[i][j] = matrix[i][j]+(j==0?0:sumMat[i][j-1]);
            }
        }
    }

    void update(int row, int col, int val) {
        int delta = (col==0?0:sumMat[row][col-1])+val-sumMat[row][col];
        
        for(int j=col; j<sumMat[0].size(); j++)  {
            sumMat[row][j]+=delta;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i=row1; i<=row2; i++) {
            ans += sumMat[i][col2]-(col1==0?0:sumMat[i][col1-1]);
        }
        return ans;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
