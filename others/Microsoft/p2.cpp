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

unordered_map<string, bool> mmap;

//int mindelete(unordered_map<string, bool> &mmap, string &str) {
int mindelete(string &str) {
    int n = str.size();
    vector<int> keep(n, INT32_MAX); // 删除第i个元素
    vector<int> leave(n, INT32_MAX); // 不删第i个元素
    keep[0] = 0;
    leave[0] = 1;
    for(int i=1; i<n; i++) {
        leave[i] = min(keep[i-1], leave[i-1])+1;
        char c1 = str[i];
        for(int j=i-1; j>=0; j--) {
            char c2 = str[j];
            string tmp;
            tmp += c1;
            tmp += c2;
            if(!mmap[tmp]) {
                if(j==0) keep[i] = min(i, keep[i]);
                continue;
            }
            keep[i] = min(keep[i], keep[j]+i-j-1);
            //break;
        }
    }
    return min(keep[n-1], leave[n-1]);
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

    //unordered_map<string, bool> mmap;
    for(int i=0; i<26; i++) {
        char c1 = i+'a';
        for(int j=0; j<26; j++) {
            char c2 = j+'a';
            string tmp;
            tmp += c1;
            tmp += c2;
            mmap[tmp] = true; // valid
        }
    }
    //cout << mmap.size() << endl;

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        string tmp1, tmp2;
        tmp1 += c1;
        tmp1 += c2;
        tmp2 += c2;
        tmp2 += c1;
        mmap[tmp1] = false;
        mmap[tmp2] = false;
    }
    //
    //cout << mindelete(mmap, str) << endl;
    cout << mindelete(str) << endl;
    return 0;
}
