/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-20T17:46:05+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-20T17:47:11+08:00
* @License: Free License
*/


/**

Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example
Consider the following matrix:

[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.

Challenge
O(log(n) + log(m)) time
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int u = 0, d = rows-1; // up and down index
        int l = 0, r = cols-1; // left and right index

        // find the last row whose element is less than target
        if(matrix[0][0] > target) return false;

        //while(u < d) {
        while(u < d) {
            int mid = (u+d)/2+1; // make the bias to right side to avoid idle loop
            if(matrix[mid][0] > target) d = mid-1;
            else if(matrix[mid][0] < target) u = mid;
            else return true;
        }

        while(l <= r) {
            int mid = (l+r)>>1;
            if(matrix[u][mid] > target) r = mid-1;
            else if(matrix[u][mid] < target) l = mid+1;
            else return true;
        }

        return false;
    }
};

/**
 * 需要方法u=mid时出现的空转情况，也就是说u=mid的条件总是满足，这时候可以调整mid
 * 的左右偏好进行调整
 * /
