/*
Rarrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:
Input : [1, 0]
Return : [0, 1]

Lets say N = size of the array. Then, following holds true:
1. All  elements in the array are in the range [0, N-1]
2. N*N does not overflow for a signed integer

*/

// 有溢出
void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //
    // 低16位时原有值，高16位是新值
	for(int i=0; i<A.size(); i++) {
        A[i] = (A[A[i]] & 0x0000FFFF)<<16 | A[i];
	}
    for(int i=0; i<A.size(); i++) {
        A[i] = A[i]>>16;
    }
}


// 参考答案
// 与上一种方法的位移区别是base选择不同
// 上一种选择2^16，而当前选择的是N
class Solution {
    public:
    void arrange(vector<int> &Vec) {
        int N = Vec.size();
        for(int i = 0; i < N; ++i) {
            Vec[i] = Vec[i] + (Vec[Vec[i]]%N) * N;
        }

        for(int i = 0; i < N; ++i) {
            Vec[i] = Vec[i] / N;
        }
    }
};
