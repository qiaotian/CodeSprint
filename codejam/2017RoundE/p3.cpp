#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define PB(x)        push_back(x)
#define MP(x,y)      make_pair(x,y)
#define CLR(x,y)     memset(x, y, sizeof(x))

#define FOR(i,l,r)   for(int i=l; i<=r; i++)
#define ROF(i,l,r)   for(int i=r; i>=l; i--)

#define IFSTREAM(x)  ifstream ifile(x)
#define OFSTREAM(y)  ofstream ofile(y)
#define CHECK()      if(!ifile || !ofile) {\
                         cout << "----> open files failed" << endl;\
                         return EXIT_FAILURE;\
                     }
#define OFILE        ofile
#define PRINT(x,t)   OFILE << "Case #" << t+1 <<": " << x << endl;
#define ICLOSE()     ifile.close()
#define OCLOSE()     ofile.close()
#define RI(x)        ifile>>x
#define RII(x,y)     RI(x),RI(y)
#define RIII(x,y,z)  RI(x),RI(y),RI(z)


int fun(int N) {
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(3, 0)));
    int r = dp.size();
    int c = dp[0].size();
    dp[0][1][0] = 1;
    dp[1][1][1] = 1;
    dp[2][1][2] = 1;
    FOR(i,1,c) {
        dp[0][i][0] = 1;
    }
    FOR(i,1,r) {
        FOR(j,2,c) {
            dp[i][j][0] = dp[i][j-1][0];
            dp[i][j][1] = dp[i-1][j-1][0] + dp[i][j-1][1];
            dp[i][j][2] = dp[i-2][j-1][0] + dp[i-2][j-1][1] + dp[i-2][j-1][2];
        }
    }
    return dp[r][c][0] + dp[r][c][1] + dp[r][c][2];
}

int main() {
    //string ipath = "./test.txt";
    //string opath = "./D-small-practice.out.txt";
    IFSTREAM("./C-large.in.txt");
    OFSTREAM("./test.out.txt");
    CHECK();

    int T;
    RI(T);

    // preprocess
    vector<vector<vector<int>>> dp(20000+1, vector<vector<int>>(20000+1, vector<int>(3, 0)));
    int r = dp.size();
    int c = dp[0].size();

    dp[0][1][0] = 1;
    dp[1][1][1] = 1;
    dp[2][1][2] = 1;
    FOR(i,1,c-1) {
        dp[0][i][0] = 1;
    }

    FOR(i,1,r-1) {
        FOR(j,2,c-1) {
            dp[i][j][0] = dp[i][j-1][0];
            dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1];
            if(i<2) continue;
            dp[i][j][2] = dp[i-2][j-1][0] + dp[i-2][j-1][1] + dp[i-2][j-1][2];
        }
    }

    FOR(t, 0, T-1) {
        int N, D;
        RII(N, D);

        long long ans = 0;
/*
        FOR(i,0,r-1) {
            FOR(j,0,c-1) {
                cout << dp[i][j][0] << " ";
                cout << dp[i][j][1] << " ";
                cout << dp[i][j][2] << "  ";
            }
            cout << endl;
        }
*/

        FOR(i, 1, N/D) { // the first number
            int first = i*D;
            if(first==N) ans+=1;
            //cout << "first is : " << first << endl;
            FOR(j, 1, N) { // the number of grid
                if(N-j*first<0) break;
                if(N-j*first>10000 || j-1>10000) break;
                ans += dp[N-j*first][j-1][0]+dp[N-j*first][j-1][1]+ dp[N-j*first][j-1][2];
            }
            //cout << ans << endl;
        }
        PRINT(ans, t);
    }

    ICLOSE();
    OCLOSE();
    return 0;
}
