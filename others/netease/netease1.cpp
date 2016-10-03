#include <iostream>
#include <vector>

using namespace std;

int util(string str, int k) {
	int n = str.size();
    int maxlen = 0;
    for(int i=0; i<k; i++) {
    	if(str[i]=='1') str[i] = '0';
        else str[i] = '1';
    }
    for(int i=0; i<n-k+1; i++) {
        if(i!=0) {
            str[i-1] = str[i-1]=='1'?'0':'1';
            str[i+k-1] = str[i+k-1]=='1'?'0':'1';
        }
        int curmax = 0;
        int curlen = 0;
    	for(int j=0; j<n; j++) {
        	if(str[j]=='0') curlen++;
            else {
                 curmax = max(curlen, curmax);
                 curlen = 0;
            }
        }
        curmax = max(curlen, curmax);
        maxlen = max(maxlen, curmax);
    }
    return maxlen;
}

int main() {
	int cnt;
    string line;
    cin >> cnt;
    for(int i=0; i<cnt; i++) {
    	int k;
        string str;
        cin >> k >> str;

       	int ans = util(str, k);
        cout << ans << endl;
    }
    return 0;
}
