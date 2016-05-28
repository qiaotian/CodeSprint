void merge_two_sorted_arrays(int* A, int* B, int m, int n) {
    int i= 0;
    for(i = m+n-1; i>=0 && m>=0 && n>=0; i--) {
        A[i] = A[m-1]>B[n-1]?A[(m--)-1]:B[(n--)-1];
    }
    while(n>=0) {
        A[i--] = B[n--];
    }
}
