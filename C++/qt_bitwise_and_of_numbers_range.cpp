// 3rd solution (代码冗长 ugly)
/*
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0) return 0;
        int moveFactor = 1;
        while(m != n){
            m >>= 1;
            n >>= 1;
            moveFactor <<= 1;
        }
        return m * moveFactor;
    }
};
*/

// 2nd solution (64ms, beats 76%)
/*
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for(int i = n-m, pos=0; i>0; i=i>>1, pos++) m &= ~(0x01 << pos);
        return m&n;
    }
};
*/

// 3rd solution (the same with 1st solution)

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       /// return 0xffffffff<<(int)floor(log(n-m))&n; //bug:n-m可能为0
       return (0xffffffff << (int)ceil(log2(n-m+1))) & m & n;
       或
       return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }
};



/**
 * WARNING
 * 本题受leetcode官方负载影响很大
 * 
 * 2nd and 3rd solution
 * 考虑到m与n相与，得到的数不会比m大，所以讲初始值置为m
 * 若n-m>=1，最后一位置0；
 * 若n-m>=2，最后两位置0；
 * 若n-m>=4，最后三位置0；
 * 以此类推
 * 最后还要与末位数
 * 
 * /