// Author : Tian Q
// Date   : 2016-05-24
// Source : https://codility.com/demo/take-sample-test/frog_jmp

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int X, int Y, int D) {
    // write your code in C99 (gcc 4.8.2)
    return (int)ceil(abs(Y-X)/(float)D);
}
