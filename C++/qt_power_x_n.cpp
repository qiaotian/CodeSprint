class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        
        long m = abs((long)n); // 负数取绝对值可能溢出
        if(m%2) {
            double tmp = myPow(x, (m-1)/2);
            return n>0?x*tmp*tmp:1/(x*tmp*tmp);
        } else {
            double tmp = myPow(x, m/2);
            return n>0?tmp*tmp:1/(tmp*tmp);
        }
    }
};

class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0){
            n = -n;
            x = 1/x; // 把x的-n次幂转化为1/x的n次幂计算
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
}

/**
 * WARNING
 * 1. n可正可负，x为浮点数
 * 2. 对负数去绝对值可能溢出
 * 3. 0的0次幂等于1
 * /
