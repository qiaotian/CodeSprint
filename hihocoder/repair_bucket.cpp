/*
Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
一只木桶能盛多少水，并不取决于桶壁上最高的那块木板，而恰恰取决于桶壁上最短的那块。

已知一个木桶的桶壁由N块木板组成，第i块木板的长度为Ai。

现在小Hi有一个快捷修补工具，每次可以使用修补工具将连续的不超过L块木板提高至任意高度。

已知修补工具一共可以使用M次(M*L<N)，如何修补才能使最短的那块木板最高呢？

注意: 木板是环形排列的，第N-1块、第N块和第1块也被视为连续的。

Input
第1行：3个正整数，N, M, L。分别表示木板数量，修补工具使用次数，修补工具每次可以同时修补的木板数。 1≤N≤1,000，1≤L≤20，M*L<N

第2行：N个正整数，依次表示每一块木板的高度Ai，1≤Ai≤100,000,000

Output
第1行：1个整数。表示使用修补工具后，最短木块的所能达到的最高高度

Hint
第一个修补工具覆盖[2 3 4]

第二个修补工具覆盖[5 8 1]



Sample Input
8 2 3
8 1 9 2 3 4 7 5
Sample Output
7
*/

#include <iostream>
#include <vector>

using namespace std;

int longest_wood(vector<int>& lens, int M, int L) {
    int ans = INT32_MAX;
    int N = lens.size();

    vector<vector<int>> dp(N, vector<int>(M+1, INT32_MAX));

    //int mini = INT32_MAX;
    //for(auto num:lens) mini = min(mini, num);
    //cout << mini << endl;
    for(int i=0; i<N; i++) dp[i][0] = lens[i];

    for(int i=1; i<M+1; i++) {
        for(int j=0; j<N; j++) {
            // 以j为起点，修补长度为L的范围
            int temp = INT32_MAX;
            for(int k=j+L; k<j+N; k++) {
                temp = min(dp[k%N][i-1], temp);
            }
            dp[j][i] = temp;
        }
    }

    for(int i=0; i<N; i++) {
        ans = min(dp[i][M], ans);
    }

    return ans;
}

int main() {
	int N, M, L;
	//cin >> N >> M >> L;
    //vector<int> lens(N, 0); // 模板长度
    //for(int i=0; i<N; i++) {
    //    cin >> lens[i];
    //}
    vector<int> lens = {8, 1, 9, 2, 3, 4, 7, 5};
    N = 8, M = 2, L = 3;
    cout << longest_wood(lens, M, L) << endl;
	return 0;
}
