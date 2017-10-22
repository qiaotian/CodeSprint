/**
 * num[i] = num[10*i], for all i
 * num[i] = num[i+1] - 1, for i%10==0
 * num[i] = num[i+1] + 1, for i%10==1
 * num[i+1] = num[(i+1)/10], for i%10==9
 */

/* 当n=10000000内存溢出
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        // 内存会超 当n=10000000时
        vector<int> count(n+1, -1); // one-based address
        count[0] = 0;
        count[1] = 1;
        for(int i=2; i<=n; i++) {
            if(count[i] != -1) continue;
            // 查看上一个数字i-1，确定当前数字i
            if((i-1)%10 == 0) {
                count[i] = count[i-1]+1;
            } else if((i-1)%10 == 1) {
                count[i] = count[i-1]-1;
            } else if((i-1)%10 == 9) {
                count[i] = count[i/10];
            } else {
                count[i] = count[i-1];
            }
            int tmp = i;
            while(10*tmp <= n) {
                count[10*tmp] = count[tmp];
                tmp *= 10;
            }
        }

        long long ret = 0;
        for(int i=1; i<=n; i++) {
            ret+=count[i];
        }
        return static_cast<int>(ret);
    }
};
*/

// 将数字n分割成两个部分a和b，a是高位部位，b是低位部分
// 比如n=x...xdy...y，那么a=x...xd，b=y...y
//

/*
class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) {
            int a = n/m, b = n%m;
            ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
        }
        return ones;
    }
};
*/

//
class Solution {
public:
    int countDigitOne(int n) {
        if(n<1) return 0;
        int ones = 0;
        long factor = 1;
        long lowernum  = 0;
        long currnum   = 0;
        long highernum = 0;

        while(n/factor) {
            lowernum  = n - (n/factor)*factor;
            currnum   = (n/factor) % 10;
            highernum = n/(factor*10); // factor*10会超过int的表示范围

            switch(currnum) {
                case 0:
                    ones += highernum * factor;
                    break;
                case 1:
                    ones += highernum * factor + lowernum + 1;
                    break;
                default:
                    ones += (highernum + 1) * factor;
                    break;
            }
            factor *= 10; // 可能会超出int的表示范围
        }
        return ones;
    }
};
