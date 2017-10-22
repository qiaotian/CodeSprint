/**
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.
*/

// Solution: This algorithm works by elimination. Every move to the left(--col) eliminates all the elements below the current cell in that column. Likewise, every move down elimnates all the elements to the left of the cell in that row.

// hard (196ms, beats 94%) O(M+N)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] < target) i++;
            else if (matrix[i][j] > target) j--;
            else return true;
        }
        return false;
    }
};
/**
 * 这道题目和之前的题目不同点在于行末尾元素值和
 * 下一行第一个元素值之间没有递增关系，所以不能
 * 做到先确定行再确定列。
 * /
