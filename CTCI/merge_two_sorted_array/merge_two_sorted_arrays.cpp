void merge_two_sorted_arrays(int* A, int* B, int m, int n) {
    for(int i = m+n-1; i>=0; i--) {
        A[i] = A[m-1]>B[n-1]?A[(m--)-1]:B[(n--)-1];
        if(b<0) return;
    }
}
