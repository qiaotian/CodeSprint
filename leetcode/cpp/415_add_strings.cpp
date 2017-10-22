/*
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int n1 = num1.size();
        int n2 = num2.size();
        int carry = 0;
        for(int i=0; i<n1 || i<n2; i++) {
            int val1 = (i<n1?num1[n1-i-1]-'0':0);
            int val2 = (i<n2?num2[n2-i-1]-'0':0);
            int curr = (val1 + val2 + carry)%10;
            carry = (val1 + val2 + carry)/10;
            ans = to_string(curr) + ans;
        }
        if(carry) ans = "1" + ans;
        return ans;
    }
};

int main() {
    Solution *sln = new Solution;
    string num1 = "1235";
    string num2 = "979";
    cout << sln->addStrings(num1, num2) << endl;
    return 0;
}
