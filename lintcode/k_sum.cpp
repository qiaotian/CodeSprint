/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-21T01:32:31+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-21T18:16:25+08:00
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

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        if(target<0) return 0;

        //int dp[A.size()+1][k+1][target+1] = ;
        vector<vector<vector<int>>> dp(A.size()+1,vector<vector<int>>(k+1, vector<int>(target+1, 0)));

        for(int i=0; i<=A.size(); i++) {
            for(int j=0; j<=k; j++) {
                for(int m=0; m<=target; m++) {
                    if(j==0 && m==0) dp[i][j][m] = 1;
                    else if(!(i==0 || j==0 || k==0)) {
                        dp[i][j][m] = dp[i-1][j][m];
                        if(m-A[i-1]>=0)
                            dp[i][j][m] += dp[i-1][j-1][m-A[i-1]];
                    }
                }
            }
        }

        return dp[A.size()][k][target];
    }
};
