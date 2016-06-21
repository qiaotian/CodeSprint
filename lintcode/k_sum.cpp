/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-21T01:32:31+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-21T09:49:25+08:00
* @License: Free License
*/



/**
Given n distinct positive integers, integer k (k <= n) and a number target.
Find k numbers where sum is target. Calculate how many solutions there are?

Example
Given [1,2,3,4], k = 2, target = 5.
There are 2 solutions: [1,4] and [2,3].
Return 2.
*/

// sln1 always gives wrong answer
class Solution {
public:
    /**
     * @param A: an integer array
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @param pos: the begining position of valid numbers in A
     * @return an integer
     */
    int util(vector<int>& A, int k, int target, int pos) {
        if(pos>=A.size() || target<0 || k<0) return 0;
        if(k==0 && target==0) return 1;
        return util(A, k-1, target-A[pos], pos+1) + util(A, k, target, pos+1);
    }

    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        sort(A.begin(), A.end());
        return util(A, k, target, 0);
    }
};
