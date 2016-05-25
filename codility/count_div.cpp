// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++11 (g++ 4.8.2)
    if(A>B || B<K) return 0;
    return (floor(1.0*B/K)+1)-(ceil(1.0*A/K));
}

// 还是要注意整数除法出现精度损失的问题
