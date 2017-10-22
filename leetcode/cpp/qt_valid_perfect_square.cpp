Difficulty: Medium
/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-29T16:10:19+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-29T19:46:06+08:00
* @License: Free License
*/



/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Returns: True

Example 2:
Input: 14
Returns: False
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long lo = 0;
        long up = num; // overflow
        while(lo <= up) {
            long mid = (lo+up)/2;
            if(mid*mid < num) lo = mid+1;
            else if(mid*mid > num) up = mid-1;
            else return true;
        }
        return false;
    }
};
