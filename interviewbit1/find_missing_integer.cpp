/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-02T14:41:48+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-02T23:29:09+08:00
* @License: Free License
* @Inc: ModelN, InMobi
*/


/**
Given an unsorted integer array, find the first missing positive integer.

Example
Given [1,2,0] return 3,
[3,4,-1,1] return 2,
[-8, -7, -6] returns 1
Your algorithm should run in O(n) time and use constant space.
*/

/*
int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count = 0; // positives integer number
    for(auto i:A) {
        if(i>0) count++;
    }
    int ans1 = count+1;
    for(int i=0; i<A.size(); i++) {
        if(A[i] >= ans1) ans1--;
    }
    int ans2 = count+1;
    for(int i=A.size()-1; i>=0; i--) {
        if(A[i] >= ans2) ans2--;
    }
    return min(ans1, ans2);
}
*/

int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    for(int i=0; i<n; i++) {
        if(A[i]<=n && A[i]>0) {
            // if(A[i] != i+1) {
            if(A[A[i]-1]!=A[i]) { //如果相等，互换没有意义
                swap(A[i], A[A[i]-1]);
                i--;
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(A[i]!=i+1) return i+1;
    }
    return n+1;
}

// 注意：A[i]-1!=i与A[A[i]-1]!=A[i]意涵不同
// 前面一句表示某一个表格的元素放置错误
// 后面一句表示某一个表格中元素所属位置与这一表格元素不同
