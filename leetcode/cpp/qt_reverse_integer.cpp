/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-01T18:20:33+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-01T18:29:54+08:00
* @License: Free License
* @Difficulty: Easy
*/

/**
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while(x) {
            ans = ans*10 + x%10;
            x/=10;
            if(ans>INT32_MAX || ans<INT32_MIN)
                return 0;
        }
        return ans;
    }
};
