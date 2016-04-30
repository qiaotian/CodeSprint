class Solution {
private:
    bool helper(int start, int len1, int len2, string& num) {
        int n = (int)num.size();
        if(2 * max(len1, len2) > n) return false;

        while(start + len1 + len2 <= n) {
            string str1 = num.substr(start, len1);
            string str2 = num.substr(start + len1, len2);
            string sum;

            int index = 0;
            int carry = 0;

            while(index < len1 || index < len2) {
                if(index < len1 && index < len2) {
                    int tmp = num[start+len1-index-1] - '0' + num[start+len1+len2-index-1] - '0' + carry;
                    carry = tmp/10;
                    sum = (char)((tmp%10)+'0') + sum;
                } else if(index < len1) {
                    int tmp = num[start+len1-index-1] - '0' + carry;
                    carry = tmp/10;
                    sum = (char)((tmp%10)+'0') + sum;
                } else {
                    int tmp = num[start+len1+len2-index-1] - '0' + carry;
                    carry = tmp/10;
                    sum = (char)((tmp%10)+'0') + sum;
                }
                index++;
            }

            if(carry) sum = (char)(carry+'0')+sum;
            if(start + len1 + len2 + sum.size() > num.size()) return false;
            if(sum == num.substr(start+len1+len2, sum.size())) {
                start += len1;
                len1 = len2;
                len2 = sum.size();
                if(start + len1 + len2 == n) return true;
            } else {
                return false;
            }
        }
        return true;
    }
public:
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) return false;

        int halflen = (int)num.size()/2;
        for(int len1 = 1; len1 <= halflen; len1++) {
            for(int len2 = 1; len2 <= halflen; len2++) {
                if(helper(0, len1, len2, num)) return true;
            }
        }
 
        return false;
    }
};
