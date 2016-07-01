/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-01T08:36:59+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-01T08:40:48+08:00
* @License: Free License
*/



/*******
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/

// 难度级别：easy

// 如果a&b为0，那么a+b就是a^b
// 如果a&b不为0，那么说明存在进位，需要将a+b转化为c+d（其中c为进位部分，d为非进位部分），
// 然后再判断c&d是否为0，依次类推

class Solution {
public:
    int getSum(int a, int b) {
        if(!(a&b)) return a^b;
        else return getSum(a^b, (a&b)<<1);
    }
};
