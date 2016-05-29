/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the previous row.

*/

// 思路：先使用二分查找找到行号，再使用二分查找找到列号 又或者将二维数组看做一位数组，两者时间复杂度一样 O(logM) + O(logN) == O(logM*N)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return -1;

        int n = matrix[0].size();
        int ll = 0;
        int rr = matrix.size()*matrix[0].size()-1;
        while(ll <= rr) {
            int mid = (ll+rr)>>1;
            if(matrix[mid/n][mid%n] == target) return true;
            else if(matrix[mid/n][mid%n] > target) rr = mid-1;
            else ll = mid+1;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0; i<rows; ++i) {
            if(target<=matrix[i][cols-1]){
                int left = 0;
                int right = cols-1;
                int mid = (left+right)/2;
                while(!(left>right)) {
                    if(matrix[i][mid]<target) left = mid+1;
                    else if(matrix[i][mid]>target) right = mid-1;
                    else return true;
                    mid = (left+right)/2;
                }
                return false;
            }
        }
        return false;
        */
        int rows = matrix.size();
        int cols = matrix[0].size();

        int down = 0;
        int up = rows-1;
        int mid_row = (up+down)/2;
        while(!(down>up)){
            if(target>matrix[mid_row][cols-1]) down=mid_row+1;
            else if(target<matrix[mid_row][0]) up=mid_row-1;
            else {
                int left = 0;
                int right = cols-1;
                int mid_col = (left+right)/2;
                while(!(left>right)){
                    if(matrix[mid_row][mid_col]<target) left = mid_col+1;
                    else if(matrix[mid_row][mid_col]>target) right = mid_col-1;
                    else return true;
                    mid_col = (left+right)/2;
                }
                return false;
            }
            mid_row = (up+down)/2;
        }
        return false;
    }
};

// NOTICE
/*
use bisection to find the correct row and column
method of bisection:
    left = mid+1, right = mid-1
    condition of breaking out: left>right
    down=mid+1, up = mid-1
    condition of breaking out: up>down
*/
