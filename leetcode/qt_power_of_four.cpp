// 不允许使用循环
/*
class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num>=4 && num%4==0) {
            num = num>>2;
        }
        return num==1;
    }
};
*/

// num&(num-1)==0，则num为2的幂，及num为00...00100...00(binary)
// num&0x55555555检测1是否在偶数位上
class Solution {
public:
    bool isPowerOfFour(int num) {
        //return num>0 && num&(num-1)==0 && num&0x55555555==num;
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) == num;
        //return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
        //return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
    }
};
// 注意 符号的优先级 '&' > '==' > '&&'
