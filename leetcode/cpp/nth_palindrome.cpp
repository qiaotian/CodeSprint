#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // n位回文的个数
    // vector<int> dp(20, 0); 不能放在这个位置
    vector<int> dp; // dp[i] is the number of palindrome whose len is i
    Solution() {
        dp = vector<int>(20, 0);
        for(int i=3; i<20; i++) {
            dp[i] = (i%2?10:1)*dp[i-1];
        }
    }
    int nthPalindrome(int n) {
        int bits = 0; // the nth palindrome has bits digits
        int ans = 0;  //

        for(int i=0, sum=0; i<20; i++) {
            sum += dp[i];
            if(sum > n) { bits = i-1; break; }
        }

        for(int i=bits; i>=0; i-=2) {
            for(int j=0; j<10; j++) {
                if(n-(j+1)*dp[bits-2] < 0) {
                    ans += 10*ans+j;
                    n -= j*dp[bits-2];
                    break;
                }
            }
        }

        int tmp = bits%2?(ans/10):ans;
        while(tmp) {
            int x = tmp%10;
            tmp /= 10;
            ans = 10*ans+x;
        }
        return ans;
    }
};
int main() {
    Solution *sln = new Solution();
    cout << sln->nthPalindrome(19) << endl;
    return 0;
}
