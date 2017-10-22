/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:59:50+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:59:51+08:00
*/



/**
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 02 = 1
*/


class Solution {
public:
    bool isHappy(int n) {
        /* Solution 1
        vector<int> vec;
        vec.push_back(n);
        while(1){
            int tmp = 0;
            while(n) {
                tmp += pow(n%10, 2);
                n /= 10;
            }
            // compare new n with all elements in vec
            for(int i=0; i<vec.size(); ++i) {
                if(vec[i]==tmp) return tmp==1;
            }
            vec.push_back(tmp);
            n = tmp;
        }
        */
        // Solution 2
        while(n>6){
            int next = 0;
            while(n){next+=(n%10)*(n%10); n/=10;}
            n = next;
        }
        return n==1;
    }
};

/**
 * NOTICE
 * Solution 1: quick enough but not elegant enough.
 * Solution 2: using fact all numbers in [2, 6] are not happy
 * (and all not happy numbers end on a cycle that hits this interval):
 * /
