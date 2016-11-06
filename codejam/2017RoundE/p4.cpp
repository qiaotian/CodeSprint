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
    IFSTREAM("./D-small-attempt0.in.txt");
    OFSTREAM("./test.out.txt");
    CHECK();

    int T;
    RI(T);
    FOR(t, 0, T-1) {
        int N, P;
        RII(N, P);
        int ans = 0;
        vector<int> nums(N,1);
        for(int i=0; i<N; i++) {
            RI(nums[i]);
        }
        for(int i=0; i<N-1; i++) {
            if(nums[i]>nums[i+1]) {
                ans++;
            }
        }
        PRINT(ans+1, t);

    }

    ICLOSE();
    OCLOSE();
    return 0;
}
