/**
* @Author: Tian Qiao
* @Date:   2016-07-13T17:32:57+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-13T17:33:19+08:00
* @Inc: Google
* @Difficulty: Easy
*/

/*
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.
You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.
Return 6.
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long l = 1, r = n;
        while(l < r) {
            long mid = (l+r)/2;
            long ret = guess(mid);
            if(ret == 0) return (int)mid;
            if(ret == 1) l = mid+1;
            else r = mid-1;
        }
        return (int)l;
    }
};

// 该题需注意到整形溢出的问题
// 无他
