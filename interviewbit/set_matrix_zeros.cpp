/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-02T14:36:40+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-02T14:41:03+08:00
* @License: Free License
* @Inc: Oracle & Amazon
* @Time: 62 min / 43min
*/



/**
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.
Do it in place.

Example
Given array A as

1 0 1
1 1 1
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.empty()||A[0].empty()) return;
    int rows = A.size();
    int cols = A[0].size();

    vector<int> flagRow(rows, 1);
    vector<int> flagCol(cols, 1);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(A[i][j]==0) {
                flagRow[i] = 0;
                flagCol[j] = 0;
            }
        }
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(flagRow[i]==0 || flagCol[j]==0) A[i][j] = 0;
        }
    }
}
// In-place algorithm has the bugs that: B depends on A, and C depends on B. If we
// modify B according to A, then C could be wrong because the B has been modified.
