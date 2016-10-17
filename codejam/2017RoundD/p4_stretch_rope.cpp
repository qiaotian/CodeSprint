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

int minPrice(vector<vector<int>>& info, int M, int L) {
    int N = info.size();

    long long dp[L+1];
    int d[L+1];
    for (int i = 1; i < L+1; i++) dp[i] = INT32_MAX;
    dp[0] = 0;

    for(auto e:info) {
        int A = e[0];
        int B = e[1];
        int P = e[2];

        int p = 0, q = 0;
        for (int j = A; L - j >= 0 && j < B; j++) {
            while (q > p && dp[d[q - 1]] >= dp[L - j]) q--;
            d[q++] = L - j;
        }
        for (int j = L; j >= 0; j--) {
            if (j - B >= 0) {
                while (q > p && dp[d[q - 1]] >= dp[j - B]) q--;
                d[q++] = j - B;
            }
            if (p < q) dp[j] = min(dp[j], dp[d[p]] + P);
            if (d[p] >= j - A) p++;
        }
    }
    if (dp[L] <= M) return dp[L];
    else return -1;
}

int main() {
    //string ipath = "./test.txt";
    //string opath = "./D-small-practice.out.txt";
    IFSTREAM("./D-large-practice.in.txt");
    OFSTREAM("./D-large-practice.out.txt");
    CHECK();

    int T;
    RI(T);
    for(int t=0; t<T; t++) {
        int N, M, L;
        RIII(N, M, L);
        vector<vector<int>> info;
        for(int i=0; i<N; i++) {
            vector<int> tmp;
            int A, B, P;
            RIII(A, B, P);
            tmp.PB(A), tmp.PB(B), tmp.PB(P);
            info.PB(tmp);
        }

        int ans = minPrice(info, M, L);
        string res = ans==-1?"IMPOSSIBLE":to_string(ans);
        PRINT(res, t);
    }

    ICLOSE();
    OCLOSE();
    return 0;
}


/*
Problem

Mary likes playing with rubber bands. It's her birthday today, and you have gone to the rubber band shop to buy her a gift.

There are N rubber bands available in the shop. The i-th of these bands can be stretched to have any length in the range [Ai, Bi], inclusive. Two rubber bands of range [a, b] and [c, d] can be connected to form one rubber band that can have any length in the range [a+c, b+d]. These new rubber bands can themselves be connected to other rubber bands, and so on.

You want to give Mary a rubber band that can be stretched to a length of exactly L. This can be either a single rubber band or a combination of rubber bands. You have M dollars available. What is the smallest amount you can spend? If it is impossible to accomplish your goal, output IMPOSSIBLE instead.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with 3 integers N, M, L, the number of rubber bands available in the shop, the number of dollars you have and the desired rubber band length. Then N lines follow. Each line represents one rubber band and consists of 3 integers, Ai, Bi, and Pi. [Ai, Bi] is the inclusive range of lengths that the i-th rubber band can stretch to, and Pi is the price of the i-th rubber band in dollars.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is IMPOSSIBLE if you cannot buy rubber bands to satisfy the goal described above, or otherwise an integer: the minimum price you can pay.

Limits

1 ≤ T ≤ 100.
1 ≤ Pi ≤ M.
1 ≤ L ≤ 10000.
1 ≤ Ai ≤ Bi ≤ 10000.
Small dataset

1 ≤ N ≤ 10.
1 ≤ M ≤ 100.
Large dataset

1 ≤ N ≤ 1000.
1 ≤ M ≤ 1000000000.
Sample


Input
2
3 8 6
3 5 2
4 4 3
1 2 5
3 11 14
1 3 4
5 5 3
2 6 5

Output
Case #1: 7
Case #2: IMPOSSIBLE

In sample case #1, none of the rubber bands in the shop are long enough on their own. It will not work to buy the two cheapest rubber bands and stick them together, because the new band would have a stretch range of [7, 9], which does not include 6. (Remember, the rubber band must be able to stretch to a length of exactly L.) The optimal solution is to buy the rubber bands costing 2 and 5 and stick them together; the new band has a stretch range of [4, 7], which does include 6. You have 8 dollars, so you can afford the total cost of 7 dollars.

In sample case #2, you need to buy all of the rubber bands to be able to stretch to length 14. That would cost 12 dollars, but you only have 11, so this case is IMPOSSIBLE.
*/
