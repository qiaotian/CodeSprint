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

    // Preprocess
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
