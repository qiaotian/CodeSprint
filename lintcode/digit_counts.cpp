/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-17T13:23:17+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-19T22:00:28+08:00
* @License: Free License
*/



/**
Count the number of k's between 0 and n. k can be 0 - 9.
Example
if n = 12, k = 1 in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
we have FIVE 1's (1, 10, 11, 12)
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        if(k>n) return 0;
        if(k==n) return 1;
        if(n==9) return 1;

        // write your code here
        int len = 1;
        while(n/len) len *= 10;
        len /= 10;
        int division = n/len;
        int remainder = n%len;
        /*
        if(division==k)
            return division*digitCounts(k, len-1) +\
                   digitCounts(k, remainder) +\
                   remainder + 1;
        else if(division>k)
            return division*digitCounts(k, len-1) +\
                   digitCounts(k, remainder) +\
                   k==0?0:len;
        else
            return division*digitCounts(k, len-1) +\
                   digitCounts(k, remainder);
                   */
        int a = division*digitCounts(k, len-1);
        int b = digitCounts(k, remainder);
        int c = k==0?0:(division<k?0:division==k?(remainder+1):len);

        return a+b+c;
    }
};

// 输入为k, 689
// a为0~599低两位中出现k的数目，不统计百位
// b为500~589中出现中出现低两位出现k的数目，不统计百位
// c为0~689中百位出现k的数目，不统计低两位出现的k
