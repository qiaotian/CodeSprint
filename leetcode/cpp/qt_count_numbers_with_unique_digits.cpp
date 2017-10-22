/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-15T20:21:59+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-15T20:26:57+08:00
* @License: Free License
*/


/**
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100,
excluding [11,22,33,44,55,66,77,88,99])

*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1; // at least one digit "0"
        for(int i=0; i<n; i++) {
            int tmp = 1;
            for(int j=0; j<i+1; j++) { // don't forget plus one
                tmp *= j==0?9:(10-j);
            }
            ans+=tmp;
        }
        return ans;
    }
};
// the total number equals numbers have 1 digit +
// numbers have two digits + ... + numbers have n
// digits

// number of digits         unique numbers
// 1                        10
// 2                        9*9
// 3                        9*9*8
// 4                        9*9*8*7
// ...                      9*9*8*7*6...
