/*
There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/


// 每次操作之后仍然是等差数列，因此可以通过
// 记录初始值、间隔以及数目来表示整个数列，无需记录数列所有值
// 
class Solution {
public:
    int lastRemaining(int n) {
        int start = 1; //当前序列的初始值
        int delta = 1; //等差数列相邻数字间隔
        int count = n; //等差数列当前数字个数
        bool l2r = true; //从左往右
        
        while(count > 1) {
            if(l2r || (count%2)) start+=delta;
            delta *= 2;
            count -= (count+1)/2;
            l2r = !l2r;
        }
        return start;
    }
};
