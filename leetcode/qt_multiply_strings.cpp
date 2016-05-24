#define MAX_NUM_LEN 1000

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;

        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> digits(MAX_NUM_LEN, 0); // 长度为1000的整数
        for(int i=0; i<len1; i++) {
            for(int j=0; j<len2; j++) {
                // 由低位到高位
                int a = num1[len1-i-1]-'0';
                int b = num2[len2-j-1]-'0';

                int carry = (a*b)/10;
                int remain = (a*b)%10;

                digits[i+j] += remain;
                digits[i+j+1] += carry;
            }
        }

        // 将某些位上大于等于10的数进行处理
        int numlen = len1+len2; //num1 * num2最大可能位数
        int carry = 0;
        for(int i=0; i<numlen; i++) {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
        }

        // 从len1+len2位开始，从后往前寻找第一个非零位
        int anslen = 0;
        for(int i=numlen; i>=0; i--){
            if(digits[i]) {
                anslen = i;
                break;
            }
            if(i==0) return "0";
        }

        for(int i=0; i<=anslen; i++) {
            char letter = digits[i]+'0';
            ans = letter + ans;
        }
        return ans;
    }
};
