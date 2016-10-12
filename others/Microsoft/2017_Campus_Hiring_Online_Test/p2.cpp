/*
P2 : Composition
Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
Alice writes an English composition with a length of N characters. However, her teacher requires that M illegal pairs of characters cannot be adjacent, and if 'ab' cannot be adjacent, 'ba' cannot be adjacent either.

In order to meet the requirements, Alice needs to delete some characters.
Please work out the minimum number of characters that need to be deleted.

Input
The first line contains the length of the composition N.
The second line contains N characters, which make up the composition. Each character belongs to 'a'..'z'.
The third line contains the number of illegal pairs M.
Each of the next M lines contains two characters ch1 and ch2,which cannot be adjacent.
For 20% of the data: 1 ≤ N ≤ 10
For 50% of the data: 1 ≤ N ≤ 1000
For 100% of the data: 1 ≤ N ≤ 100000, M ≤ 200.

Output
One line with an integer indicating the minimum number of characters that need to be deleted.

Sample Hint
Delete 'a' and 'd'.

Sample Input
5
abcde
3
ac
ab
de
Sample Output
2
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 全局变量方便调用
// 数组做形参传递比较麻烦，需要知道明确声明维数，不然需要使用二级指针（手动寻址）
int dt[26][26]; // dict maps characters pair to valid or not

int mindelete(string& str) {
    int n = str.size();
    int dp[n][26];  //
    memset(dp, n, sizeof(dp));
    for(int i=0; i<n; i++) {
        for(int j=0; j<26; j++) {
            // 以(j+'a')结尾
            if(i==0) {
                dp[i][j] = j==(str[i]-'a')?0:1;
                continue;
            }

            if(j==str[i]-'a') {
                // 当前字符是(j+'a'),当前字符可能删除,可能保留
                for(int k=0; k<26; k++) {
                    if(!dt[k][j]) dp[i][j] = min(dp[i-1][k], dp[i][j]);
                }
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            } else {
                // 当前字符不是(j+'a'),必须删除但钱字符
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }
        }
    }
    int ans = n;
    for(int i=0; i<26; i++) {
        ans = min(ans, dp[n-1][i]);
    }
    return ans;
}

int main() {
    int N;
    string str;
    cin >> N;
    for(int i=0;i<N; i++) {
        char c;
        cin >> c;
        str += c;
    }

    memset(dt, 0, sizeof(dt)); // allowed

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        dt[c1-'a'][c2-'a'] = 1;
        dt[c2-'a'][c1-'a'] = 1;
    }

    cout << mindelete(str) << endl;
    return 0;
}
