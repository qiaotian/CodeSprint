/**
* @Author: Tian Qiao
* @Date:   2016-08-03T01:50:12+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-03T01:50:24+08:00
* @Inc: Google
* @Difficulty: Hard
*/

/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
*/

// TLE O(N^4) Brute Force
/*
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = m==0?0:matrix[0].size();

        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]<=k) ans = matrix[i][j];

                if(i==0 && j==0) continue;
                else if(i==0 && j!=0) matrix[i][j] += matrix[i][j-1];
                else if(i!=0 && j==0) matrix[i][j] += matrix[i-1][j];
                else matrix[i][j] += matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
            }
        }


        for(int h=1; h<=m; h++) {
            for(int w=1; w<=n; w++) {
                for(int i=0; i<m-h+1; i++) {
                    for(int j=0; j<n-w+1; j++) {
                        int sum = 0;
                        if(i==0 && j==0)      sum = matrix[i+h-1][j+w-1];
                        else if(i==0 && j!=0) sum = matrix[i+h-1][j+w-1]-matrix[i][j-1];
                        else if(i!=0 && j==0) sum = matrix[i+h-1][j+w-1]-matrix[i-1][j];
                        else                  sum = matrix[i+h-1][j+w-1]-matrix[i-1][j]-matrix[i][j-1]+matrix[i-1][j-1];
                        cout << sum << endl;
                        ans = max(ans, sum<=k?sum:INT32_MIN);
                    }
                }
            }
        }
        return ans;
    }
};
*/

// 1D Kadane Algo: O(N)
// 1D Kadane (no larger than K): O(N*logN)
// 2D Kadane Algo: O(min(M,N)^2*max(M,N))
// 2D Kadane (no larger than K): O(min(M,N)*min(M,N)*max(M,N)log max(M,N)), Space: O(max(M,N))
// Follow up: if m >>> n, we should operate the transposed matrix

// 2D Kadane Algo Video Tutorial: https://www.youtube.com/watch?v=yCQN096CwWM
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT32_MIN;

        if(matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = rows==0?0:matrix[0].size();

        for(int l=0; l<cols; l++) {
            vector<int> sums(rows, 0); // extra space O(M)
            for(int r=l; r<cols; r++) {
                for(int i=0; i<rows; i++) {
                    sums[i]+=matrix[i][r];
                }
                // find the maximum subarray no more than k

                set<int> s; //
                s.insert(0);
                int curmax = INT32_MIN, cursum = 0;
                for(int val:sums) {
                    cursum += val;
                    set<int>::iterator it = s.lower_bound(cursum - k);
                    if (it != s.end()) curmax = std::max(curmax, cursum - *it);
                    s.insert(cursum);
                }
                ans = max(ans, curmax);
            }
        }

        return ans;
    }
};
