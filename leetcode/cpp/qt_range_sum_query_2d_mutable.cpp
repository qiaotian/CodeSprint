/**
* @Author: Tian Qiao
* @Date:   2016-08-04T14:22:43+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-04T14:22:45+08:00
* @Inc: Google
* @Difficulty: Hard
* @Tag: Binay Index Tree, Segment Tree
*/

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


// 1 该解决方案没有使用线段树，而是简单对行做累加
// 更新O(N)
// 查询O(M)
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


// 2 二维线段树的实现，复杂
//
class TreeNode {
    int row1; // 当前节点的作用范围
    int col1; // 单前节点
    int row2;
    int col2;
    int sum;
    TreeNode* topLeft, *topRight, *bottomLeft, *bottomRight;
    TreeNode(int row1, int col1, int row2, int col2, int sum) {
        this.row1 = row1;
        this.col1 = col1;
        this.row2 = row2;
        this.col2 = col2;
        this.sum = sum;
        topLeft = topRight = bottomLeft = bottomRight = NULL;
    }
};

class NumMatrix {
private:
    TreeNode* root;
    int row;
    int col;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        row = matrix.length;
        col = matrix[0].length;
        root = build(matrix, 0, 0, row - 1, col - 1);
    }

    void update(int row, int col, int val) {
        modify(root, row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(root, row1, col1, row2, col2);
    }

    TreeNode build(vector<vector<int>>& matrix, int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2) {
            return NULL;
        }
        if (row1 == row2 && col1 == col2) {
            return new TreeNode(row1, col1, row2, col2, matrix[row1][col1]);
        }
        int midRow = (row1 + row2) / 2;
        int midCol = (col1 + col2) / 2;
        TreeNode* topLeft = build(matrix, row1, col1, midRow, midCol);
        TreeNode* topRight = build(matrix, row1, midCol + 1, midRow, col2);
        TreeNode* bottomLeft = build(matrix, midRow + 1, col1, row2, midCol);
        TreeNode* bottomRight = build(matrix, midRow + 1, midCol + 1, row2, col2);
        int sum = 0;
        sum += topLeft != NULL ? topLeft.sum : 0;
        sum += topRight != NULL ? topRight.sum : 0;
        sum += bottomLeft != NULL ? bottomLeft.sum : 0;
        sum += bottomRight != NULL ? bottomRight.sum : 0;
        TreeNode* node = new TreeNode(row1, col1, row2, col2, sum);
        node->topLeft = topLeft;
        node->topRight = topRight;
        node->bottomLeft = bottomLeft;
        node->bottomRight = bottomRight;
        return node;
    }

    void modify(TreeNode* root, int row, int col, int value) {
        if (root == NULL) {
            return;
        }
        if (root.row1 == root.row2 && root.col1 == root.col2 && root.row1 == row && root.col1 == col) {
            root.sum = value;
            return;
        }
        int midRow = (root.row1 + root.row2) / 2;
        int midCol = (root.col1 + root.col2) / 2;
        if (root.row1 <= row && row <= midRow) {
            if (root.col1 <= col && col <= midCol) {
                modify(root.topLeft, row, col, value);
            } else if (midCol + 1 <= col && col <= root.col2) {
                modify(root.topRight, row, col, value);
            }
        } else if (midRow + 1 <= row && row <= root.row2) {
            if (root.col1 <= col && col <= midCol) {
                modify(root.bottomLeft, row, col, value);
            } else if (midCol + 1 <= col && col <= root.col2) {
                modify(root.bottomRight, row, col, value);
            }
        }
        int sum = 0;
        sum += root.topLeft != NULL ? root.topLeft.sum : 0;
        sum += root.topRight != NULL ? root.topRight.sum : 0;
        sum += root.bottomLeft != NULL ? root.bottomLeft.sum : 0;
        sum += root.bottomRight != NULL ? root.bottomRight.sum : 0;
        root.sum = sum;
    }

    int query(TreeNode* root, int row1, int col1, int row2, int col2) {
        if (root == NULL || row1 > row2 || col1 > col2) {
            return 0;
        }
        if (root.row1 == row1 && root.col1 == col1 && root.row2 == row2 && root.col2 == col2) {
            return root.sum;
        }
        int midRow = (root.row1 + root.row2) / 2;
        int midCol = (root.col1 + root.col2) / 2;
        if (root.row1 <= row2 && row2 <= midRow) {
            // top
            if (root.col1 <= col2 && col2 <= midCol) {
                // top left
                return query(root.topLeft, row1, col1, row2, col2);
            } else if (midCol + 1 <= col1 && col1 <= root.col2) {
                // top right
                return query(root.topRight, row1, col1, row2, col2);
            } else {
                // top left + top right
                return query(root.topLeft, row1, col1, row2, midCol) + query(root.topRight, row1, midCol + 1, row2, col2);
            }
        } else if (midRow + 1 <= row1 && row1 <= root.row2) {
            // bottom
            if (root.col1 <= col2 && col2 <= midCol) {
                // bottom left
                return query(root.bottomLeft, row1, col1, row2, col2);
            } else if (midCol + 1 <= col1 && col1 <= root.col2) {
                // bottom right
                return query(root.bottomRight, row1, col1, row2, col2);
            } else {
                // bottom left + bottom right
                return query(root.bottomLeft, row1, col1, row2, midCol) + query(root.bottomRight, row1, midCol + 1, row2, col2);
            }
        } else {
            // top + bottom
            if (root.col1 <= col2 && col2 <= midCol) {
                // top left + bottom left
                return query(root.topLeft, row1, col1, midRow, col2) + query(root.bottomLeft, midRow + 1, col1, row2, col2);
            } else if (midCol + 1 <= col1 && col1 <= root.col2) {
                // top right + bottom right
                return query(root.topRight, row1, col1, midRow, col2) + query(root.bottomRight, midRow + 1, col1, row2, col2);
            } else {
                // top left + top right + bottom left + bottom right
                return query(root.topLeft, row1, col1, midRow, midCol) + query(root.topRight, row1, midCol + 1, midRow, col2) +
                query(root.bottomLeft, midRow + 1, col1, row2, midCol) + query(root.bottomRight, midRow + 1, midCol + 1, row2, col2);
            }
        }
    }
}


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
