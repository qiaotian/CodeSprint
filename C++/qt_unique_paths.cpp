// TLE for large numbers
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n == 1 || m == 1) return 1;
        return uniquePaths(m, n-1) + uniquePaths(m-1, n);
    }
};
*/

// C(m+n, n) overflow
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long numerator = 1, denominator = 1;
        for(int i = m; i <= m + n -2; i++) denominator *= i;
        for(int i = 1; i <= n-1; i++) numerator *= i;
        return denominator/numerator;
    }
};
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        double res = 1.0;
        for(int i = 1; i <= n-1; i++) res *= (m+i-1)/i;
        return (int)res;
    }
};

/**
 * WARNING
 * 1. 当m+i-1和i都是整数时，其比值亦为整数，造成精度损失
 * 2. 强制类型转换的优先级高于四则运算，仅次于[]、取值、和负运算符‘-’
 * /
