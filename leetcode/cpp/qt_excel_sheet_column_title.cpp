/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:46:44+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:46:46+08:00
* @Tag: Math
*/

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        char tmp;
        while(n) {
            n = n-1;
            tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        return res;
    }
};

/****
 * 1. system of carry of 26 but there is no zero!
 * 2. char type could be converted string type automatically!
 * /
