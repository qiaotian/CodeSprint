/*
Problem

A and B are the only two candidates competing in a certain election. We know from polls that exactly N voters support A, and exactly M voters support B. We also know that N is greater than M, so A will win.

Voters will show up at the polling place one at a time, in an order chosen uniformly at random from all possible (N + M)! orders. After each voter casts their vote, the polling place worker will update the results and note which candidate (if any) is winning so far. (If the votes are tied, neither candidate is considered to be winning.)

What is the probability that A stays in the lead the entire time -- that is, that A will always be winning after every vote?

Input

The input starts with one line containing one integer T, which is the number of test cases. Each test case consists of one line with two integers N and M: the numbers of voters supporting A and B, respectively.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the probability that A will always be winning after every vote.

y will be considered correct if y is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits

1 ≤ T ≤ 100.
Small dataset

0 ≤ M < N ≤ 10.
Large dataset

0 ≤ M < N ≤ 2000.
Sample


Input
2
2 1
1 0

Output
Case #1: 0.33333333
Case #2: 1.00000000

In sample case #1, there are 3 voters. Two of them support A -- we will call them A1 and A2 -- and one of them supports B. They can come to vote in six possible orders: A1 A2 B, A2 A1 B, A1 B A2, A2 B A1, B A1 A2, B A2 A1. Only the first two of those orders guarantee that Candidate A is winning after every vote. (For example, if the order is A1 B A2, then Candidate A is winning after the first vote but tied after the second vote.) So the answer is 2/6 = 0.333333...

In sample case #2, there is only 1 voter, and that voter supports A. There is only one possible order of arrival, and A will be winning after the one and only vote.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//#define PB          push_back
#define MP(x,y)     make_pair(x,y)
#define CLR(x,y)    memset(x, y, sizeof(x))

#define FOR(i,l,r)   for(int i=l; i<=r; i++)
#define ROF(i,l,r)   for(int i=r; i>=l; i--)

#define RI(x)        ifile>>x
#define RII(x,y)     RI(x),RI(y)
#define RIII(x,y,z)  RI(x),RI(y),RI(z)

int main() {
    // double a[2000][2000];段错误，内存超标 (8B*2000*2000 = 32MB > 1M)
    string ipath = "/Users/qiaotian/Downloads/CodeSprint/codejam/2017RoundD/A-large-practice.in.txt";
    string opath = "/Users/qiaotian/Downloads/CodeSprint/codejam/2017RoundD/outtest.txt";

    ifstream ifile(ipath);
    ofstream ofile(opath);

    if(!ifile || !ofile) {
        cout << "----> open files failed" << endl;
        return EXIT_FAILURE;
    }

    int T;
    RI(T);
    for(int t=0; t<T; t++) {
        int M, N;
        RII(N, M);

        //double dp[N+1][M+1]; // 内存超标
        double dp[N+1];
        CLR(dp, 0.0);
        for(int i=1; i<=N; i++) {
            dp[i] = 1.0;
        }

        for(int j=1; j<=M; j++) {
            for(int i=j; i<=N; i++) {
                if(i==j) {
                    dp[i] = 0;
                    continue;
                }
                //dp[i][j] = (i*dp[i-1][j] + j*dp[i][j-1])/(i+j);
                //cout << i << " " << j << dp[i][j] << endl;
                dp[i] = (i*dp[i-1] + j*dp[i])/(i+j);
            }
        }
        ofile << "Case #" << t+1 <<": " << dp[N] << endl;
    }

    ifile.close();
    ofile.close();
    return 0;
}
