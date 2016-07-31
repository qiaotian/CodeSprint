/**
* @Author: Tian Qiao
* @Date:   2016-07-30T21:52:41+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-30T21:52:43+08:00
* @Inc: Adobe, Microsoft
* @Difficulty: Easy
*/



/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?
You may find this Wikipedia article useful.
*/

// O(?)
class Solution {
public:
    int addDigits(int num) {
        int cpy = num;
        while(cpy>=10){
            int sum = 0;
            while(cpy){
                sum+=cpy%10;
                cpy/=10;
            }
            cpy = sum;
        }
        return cpy;
    }
};

// O(1)
// https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
