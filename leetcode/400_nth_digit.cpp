/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
Hide Company Tags
*/

class Solution {
    public:
        int findNthDigit(int n) {
            int d = 1, base = 1;
            while(n > (long long)9*base*d) {
                n -= 9*base*d;
                d++;
                base *= 10;
            }
            // 此时，n变成从base到目标字符的所有字符数目
            // 从base到第n个字符所在的整数之间的所有数字具有相同位数d
            int num = base + (--n)/d;
            for(int i=0; i<d-n%d; i++) num/=10;
            return num%10;
        }
}
