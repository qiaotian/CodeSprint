// 难点：如何用O(N)复杂度解决该文题
// 思路：Every slice must be of size two or three. Slices of bigger sizes are created from such smaller slices. Therefore should any bigger slice have an optimal value, all sub-slices must be the same, for this case to hold true. Should this not be true, one of the sub-slices must be the optimal slice. The others being bigger. Therefore we check all possible slices of size 2/3 and return the smallest one. The first such slice is the correct one.
// 做法：检查所有长度为2或者3的slice，找到最小值，比较的时候注意不能使用'<='，要用’<’

int solution(vector<int> &A) {
    //vector<int> sum(A.size(), 0);
    //for(int i=0; i<A.size(); i++) {
    //    sum[i] = A[i]+(i==0?0:sum[i-1]);
    //}
    int index = 0;
    int min_avg = INT32_MAX;
    for(int i=0; i<A.size()-1; i++) {
        if((A[i]+A[i+1])/2 < min_avg) {
            index = i;
            min_avg = (A[i]+A[i+1])/2;
        }
        if (i<A.size()-2 && (A[i]+A[i+1]+A[i+2])/3<min_avg) {
            index = i;
            min_avg = (A[i]+A[i+1]+A[i+2])/3;
        }
    }
    return index;
}
