#include <iostream>
#include <vector>

using namespace std;

int cut(int N, vector<long long>& sum) {
    for(int i=0; i<sum.size(); i++) {
    	if(sum[i]>N) return i;
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    vector<long long> dp(100, 0);
    vector<long long> sum(100, 0);
    dp[0] = 1; dp[1] = 2;
    sum[0] = 1;
    sum[1] = 3;
    for(int i=2; i<dp.size(); i++) {
    	dp[i] = dp[i-1]+dp[i-2];
        sum[i] = sum[i-1] + dp[i];
    }
    for(int i=0; i<dp.size(); i++) {
        // cout << i << " " << dp[i] << " " << sum[i] << endl;
    }

    for(int i=0; i<T; i++) {
    	int N;
        cin >> N;
        cout << cut(N, sum) << endl;
    }
	return 0;
}
