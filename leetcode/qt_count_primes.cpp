/**
* @Author: Tian Qiao
* @Date:   2016-08-06T10:03:12+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-06T10:03:16+08:00
* @Inc: Microsoft, Amazon
* @Difficulty: Medium
* @HashTable, Math
*/


/*
Description:
Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        // Solution One (300ms)
        /*
        if(n<=2) return 0;

        vector<bool> flag(n, true);// store 0~n-1
        int count = 0; // the number of prime less than 3 is 1
        for(int i=2; i<n; ++i) {
            if (flag[i]) {
                count++;
                int times = 2;
                while(times*i<n) {
                    flag[times*i] = false;
                    times++;
                }
            }
        }
        return count;
        */

        // Solution Two (fastest with 12ms)
        if(--n < 2) return 0;
        int m = (n+1)/2;
        int ans = m; // 初始化数目为m
        int k, u = (sqrt(n)-1)/2;
        bool notPrime[m] = {0};

        for(int i=1; i<=u; i++)
            if(!notPrime[i])
                for(k=(i+1)*2*i; k<m; k+=i*2+1)
                    if (!notPrime[k]) {
                        notPrime[k] = true;
                        ans--; //排除一个合数，ans自减
                    }
        return ans;
        // Solution Three (less space with 16ms)
        /*
        if(--n < 2) return 0;
        char notPrime[(n + 1)/16+1] = {0};
        int count = (n+1)/2, k,  u = (sqrt(n) - 1)/2;

        for(int i = 1; i <= u;i++)
            if(!(notPrime[i>>3] & (1<<(i&7))))
                for(k = 2*i*(i + 1); k < (n + 1)/2;k += 2* i + 1)
                if (!(notPrime[k>>3] & (1<<(k&7)))) {
                    notPrime[k>>3] |= (1<<(k&7));
                    count--;
                }
        return count;
        */
    }
};

/***
 * 从前往后，先后排除2的倍数，3的倍数，5的倍数。。。
 * 那么当数字由小增大时，如果flag为true，说明
 * 所以小于该数的数字都不能整除，符合素数条件。
 * /
