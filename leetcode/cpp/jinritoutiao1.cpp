#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 以特定字符开头的长度最大为n的数字个数
vector<int> dp(18, 0);

string mthNumber(int n, int m) {
    if(m==1) return "1";

    string ans = "";
    int tmp = m;
    
    while(tmp) {
        //第一个字母从1~9
        for(int i=18; i>=0; i--) {
            int num = tmp/dp[i];
            ans += to_string(num);
            tmp -= num*dp[i];
        }
    }
}

int main() {
    for(int i=1; i<dp.size(); i++) {
        dp[i] = dp[i-1]*10+1;
    }

    return 0;
}
