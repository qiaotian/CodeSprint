/**
 * @Author: qiao
 * @Date:   2017-08-14T20:53:11+08:00
 * @Email:  qiaotian@me.com
 * @Last modified by:   qiao
 * @Last modified time: 2017-08-15T18:19:57+08:00
 * @License: MIT
 * @Copyright: qiaotian
 */



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

int main() {
    //string ipath = "./test.txt";
    //string opath = "./D-small-practice.out.txt";
    IFSTREAM("./B-large.in.txt");
    OFSTREAM("./test.out.txt");
    CHECK();

    int T;
    RI(T);
    FOR(t, 0, T-1) {
        long long N;
        RI(N);
        long long base = 2;
        for(long long i=2; i<=N; i++) {
            long long cpy = N;
            while(cpy % i == 1) {
                cpy /= i;
            }
            if(cpy==0) {
                base = i;
                break;
            }
        }
        /*
        int N, M, L;
        RIII(N, M, L);
        vector<vector<int>> info;
        FOR(i, 0, N-1) {
            vector<int> tmp;
            int A, B, P;
            RIII(A, B, P);
            tmp.PB(A), tmp.PB(B), tmp.PB(P);
            info.PB(tmp);
        }
        */
        // int ans = minPrice2(info, M, L);
        //int ans = minPrice(info, M, L);
        //string res = ans==-1?"IMPOSSIBLE":to_string(ans);
        PRINT(base, t);

    }

    ICLOSE();
    OCLOSE();
    return 0;
}
