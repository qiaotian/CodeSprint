/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:44:51+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:45:10+08:00
* @Difficulty: Easy
* @Tag: Math
* @Inc: MS, Uber
*/

/*
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

class Solution {
public:
    int titleToNumber(string s) {
        int out = 0;
        for(int i=0; i<s.size(); ++i){
            int digit = s[i]-64;
            out += digit*pow(26, s.size()-i-1);
        }
        return out;
    }
};

// WARN
/**
 * 26 carry system
 * '^' in cpp is bit operator, called xor.
 * Therefore, 26^(0) is 26, not 1.
 * use pow(x, n);
 * */
