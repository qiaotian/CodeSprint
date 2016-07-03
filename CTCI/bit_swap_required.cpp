/**
* @Author: Tian Qiao
* @Date:   2016-07-03T17:56:43+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T18:00:56+08:00
*/



Write a function to determine the number of bits required to convert integer A to integer B.
Input: 31, 14
Output: 2

________________________________________________________________________________

This seemingly complex problem is actually rather straihtforward. To approach this, ask yourself how you would figure out which bits in two numbers are different. Simple: with an xor.

Each 1 in the xor will represent one different bit between A and B. We then simply need to count the number of bits that are 1.

class Solution{
public:
    int bitSwapRequired(int a, int b) {
        int count = 0;
        for(int c=a^b; c!=0; c=c>>1) {
            count+=c&1;
        }
        return count;
    }
};
