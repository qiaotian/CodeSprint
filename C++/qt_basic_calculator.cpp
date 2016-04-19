/*class Solution {
public:
    int calculate(string s) {
        stack<int> nums; // 数字
        stack<char> opts; // 括号和计算符号
        
        // 1. preprocess
        int number = 0;
        for(char c : s) {
            if(c>='0' && c<='9') {
                number *= 10;
                number += (i-'0');
            }
            if(c=='+' || c=='-' || c=='(' || c == ')') {
                opts.push_back(c);
                if(number) nums.push(number);
                number = 0;
            }
            if(c ==' ') {
                if(number) nums.push(number);
                number = 0;
                continue;
            }
        }
        if(number) nums.push(number);
        
        // 2. caculation
        int left = 0, right = 9;
        while(!opts.empty()) {
            char cur = opts.top();
            opts.pop();
            if(cur == ')') {
                while(cur != '(') {
                    
                }    
            }
        }
    }
};
*/
class Solution {
public:
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};

/**
 * WARNING
 * 1. 不用处理负数的问题，省去很多麻烦，可是需要将字符串转数字；
 * 2. 空格直接跳过，也不麻烦；
 * 3. 计算只存在加和减，那么无需考虑乘除的运算符重排，从左至右顺序计算即可；
 * 4. 主要工作的就是控制计算顺序和字符串与数字转换
 * /
