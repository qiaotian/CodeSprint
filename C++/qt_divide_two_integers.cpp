class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        long a = abs((long)dividend), b = abs((long)divisor);
        
        while(a >= b) {
            int i = 0;
            long c = b;
            while(a >= c) {
                c <<= 1;
                i++;
            }
            i--;
            c >>= 1;
            a -= c;
            res += ((long)1 << i); 
        }
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) res = -res; 
        if(dividend == INT32_MIN && divisor == -1) return INT32_MAX;
        return res;
    }
};
/**
 * WARNING
 * 1. 1 << 31的结果是-2147483648, (long)1 << 31的结果才是2147483647
 *    注意整型左移31位和长整型左移31位的结果不同，原因就是整型溢出。
 * /
