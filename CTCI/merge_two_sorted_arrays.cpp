/**
* @Author: Tian Qiao <root>
* @Date:   2016-05-28T21:20:33+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-06-25T23:54:46+08:00
* @License: Free License
*/



/*
You are given two sorted arrays, A and B, and A has large enough bugger at the end to hold B. Write a method to merge B into A in sorted order.
*/

void merge_two_sorted_arrays(int* A, int* B, int m, int n) {
    int i= 0;
    for(i = m+n-1; i>=0 && m>=0 && n>=0; i--) {
        A[i] = A[m-1]>B[n-1]?A[(m--)-1]:B[(n--)-1];
    }
    while(n>=0) {
        A[i--] = B[n--];
    }
}
