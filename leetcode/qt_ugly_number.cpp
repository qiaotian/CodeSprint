/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T15:41:33+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T15:42:35+08:00
*/



Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
Note that 1 is typically treated as an ugly number.


class Solution {
public:
    bool isUgly(int num) {
        //if(num==1) return true; not necessary
        if(num==0) return false;
        while(num%2==0) num/=2;
        while(num%3==0) num/=3;
        while(num%5==0) num/=5;
        return num==1;
    }
};

/**
 * NOTICE
 * Solution 1 cost 8ms, but someone gives 4ms.
 * If you run the same code few times during a day,
 * it will give different time results.
 * I think it depends on server loading.
 * /
