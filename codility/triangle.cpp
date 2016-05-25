// 思路：使用快速排序以后，对于数组中任意的三个数a,b,c，且a<=b<=c，则只要满足a+b>c即abc三条边就一定构成三角形，理由很简单，因为a<=b<=c，就意味着b+c>a和a+c>b已经成立，所以只要找到a+b>c即可.

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    for(int i=2; i<A.size(); i++) {
        if(A[i-2]+A[i-1]>A[i]) return 1;
    }
    return 0;
}
