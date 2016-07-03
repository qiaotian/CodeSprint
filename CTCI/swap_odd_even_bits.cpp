/**
* @Author: Tian Qiao
* @Date:   2016-07-03T18:26:50+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T18:32:33+08:00
*/

/*Write a program to swap odd and even bits in an integer with as few instructions as possible(e.g. bit0 and bit1 are wapped, bit2 and bit3 are swapped, etc).*/

________________________________________________________________________________

/*Mask all odd bits with 10101010 in binary (which is 0xAA), then shift them left to put them in the even bits. Then perform a similiar operation for even bits. This takes a total 5 instructions.*/

class Solution {
public:
    int swapOddEvenBits(int x) {
        return ((x & 0xaaaaaaaa)>>1) | ((x & 0x55555555)<<1);
    }
};
