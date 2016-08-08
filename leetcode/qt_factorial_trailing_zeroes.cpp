/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:50:54+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:50:57+08:00
*/



/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        /*double logVal = 0.0;
        for(int i=0; i<n; ++i) {
            logVal += log(i+1)/log(10);
        }
        return (int)logVal;*/ // timeout

        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
/***
 * Because all trailing 0 is from factors 5 * 2.
 * But sometimes one number may have several 5 factors, for example, 25 have two 5 factors, 125 have three 5 factors.
 * In the n! operation, factors 2 is always ample.
 * So we just count how many 5 factors in all number from 1 to n.
 * /
