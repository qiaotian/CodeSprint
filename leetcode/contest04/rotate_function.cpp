/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.

*/

// TLE, O(N^2)
class Solution {
public:
    int Fk(vector<int>& A, int k) {
        int sum = 0;
        int n = A.size();
        for(int i=1; i<n; i++) {
            sum += i*A[(i+n-k%n)%n];
        }
        return sum;
    }
    int maxRotateFunction(vector<int>& A) {
        int ans = INT32_MIN;
        int n = A.size();
        
        if(n==0) return 0;
        
        for(int k=0; k<n; k++) {
            int tmp = Fk(A, k);
            ans = max(tmp, ans);
        }
        return ans;
    }
};

// O(N)
// find the relationship between f[k] and f[k+1]
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0,len = A.size(),startResult = 0;
        for(int i = 0;i<len;i++){
            startResult += i*A[i];
            sum += A[i];
        }
        int maxResult = startResult;
        
        for(int i = len-1;i>=0;i--){
            startResult += sum - len*A[i];
            maxResult = max(maxResult,startResult);
        }
        return maxResult;
    }
};

