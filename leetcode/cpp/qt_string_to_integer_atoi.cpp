/**
 * 删除开头空格
 * 开始的‘+’‘-’号的个数可能不止一个，此时数字不合法，返回0
 * 可能产生越界的情况，返回MAX_INT或MIN_INT
 * 大数据类型不足以应对所有的Test Cases
 */
// 1. +-3
//

class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        int end = str.size()-1;
        while(start<=end && (str[start]==' ' || str[end]==' ')) {
            if(str[start]==' ') start++;
            if(str[end]==' ') end--;
        }
        if(start>end) return 0; //全部是空字符则返回0

        long ans = 0; //即使定义为long类型也可能会超，只依赖大整数类型的思路是错误的
        int flag = 1; //

        if(str[start]=='+' || str[start]=='-') {
            flag = str[start]=='+'?1:-1;
            start++;
            if(start>end) return 0; // 排除 str==“+”类似情况
        }

        for(int i=start; i<=end; i++) {
            if(str[i]=='-' || str[i]=='+') {
                return 0;
            }
            if(str[i]<'0' || str[i]>'9') {
                break;
            }
            ans = ans*10+str[i]-'0';
            if(ans>INT_MAX) break;
        }

        ans *= flag;

        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;

        return (int)ans;
    }
};
