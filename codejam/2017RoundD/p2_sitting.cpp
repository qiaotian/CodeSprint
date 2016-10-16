/*
The Codejamon game is on fire! Many players have gathered in an auditorium to fight for the World Championship. At the opening ceremony, players will sit in a grid of seats with R rows and C columns.

The competition will be intense, and the players are sensitive about sitting near too many of their future opponents! A player will feel too crowded if another player is seated directly to their left and another player is seated directly to their right. Also, a player will feel too crowded if one player is seated directly in front of them and another player is seated directly behind them.

What is the maximum number of players that can be seated such that no player feels too crowded?
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of one line with two integers R and C: the number of rows and columns of chairs in the auditorium.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of players that can be seated, as described in the problem statement.

Limits

1 ≤ T ≤ 100.
Small dataset

1 ≤ R ≤ 5.
1 ≤ C ≤ 5.
Large dataset

1 ≤ R ≤ 100.
1 ≤ C ≤ 100.
Sample

Input
3
2 2
2 3
4 1

Output
Case #1: 4
Case #2: 4
Case #3: 3
In sample case #1, we can fill all seats, and no player will feel too crowded.

In sample case #2, each row has three seats. We can't put three players in a row, since that would make the middle player feel too crowded. One optimal solution is to fill each of the first two columns, for a total of four players.

In sample case #3, one optimal solution is to fill the first two rows and the last row, for a total of three players.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define PB          push_back
#define MP(x,y)     make_pair(x,y)
#define CLR(x,y)    memset(x, y, sizeof(x))

#define FOR(i,l,r)   for(int i=l; i<=r; i++)
#define ROF(i,l,r)   for(int i=r; i>=l; i--)

#define RI(x)        ifile>>x
#define RII(x,y)     RI(x),RI(y)
#define RIII(x,y,z)  RI(x),RI(y),RI(z)

int maxSittings(int R, int C) {
    // 上下左右添加 margin
    // pair的first表示当前位置被占用时的最大数目
    // pair的second表示当前位置没有被占用的最大数目
    /*
    vector<vector<pair<int, int>>> mat(R, vector<pair<int,int>>(C, {0,0}));
    mat[0][0] = {1, 0};
    mat[0][1] = {2, 1};
    mat[1][0] = {2, 1};
    mat[1][1] = {4, 3};
    // 第一列 & 第二列
    for(int i=2; i<R; i++) {
        mat[i][0].first  = max(mat[i-2][0].second+2, mat[i-1][0].second+1);
        mat[i][0].second = max(mat[i-1][0].first, mat[i-1][0].second);

        mat[i][1].first  = max(mat[i-2][1].second+2, mat[i-1][1].second+1);
        mat[i][1].second = max(mat[i-1][1].first, mat[i-1][1].second);
    }
    // 第一行 & 第二行
    for(int j=2; j<C; j++) {
        mat[0][j].first  = max(mat[0][j-2].second+2, mat[0][j-1].second+1);
        mat[0][j].second = max(mat[0][j-1].first, mat[0][j-1].second);

        mat[1][j].first  = max(mat[1][j-2].second+2, mat[1][j-1].second+1);
        mat[1][j].second = max(mat[1][j-1].first, mat[1][j-1].second);
    }
    for(int i=1; i<R; i++) {
        for(int j=1; j<C; j++) {
            // left and top are empty
            int tmp1 = mat[i-1][j].second + mat[i][j-1].second;
            int tmp2 = mat[][].second + mat[][];
            mat[i][j].first = max(mat[i-1][j].second+mat[][);
        }
    }
    */
    // 贪心
    /* A代表有人，O代表空
    AAO|AAO|AAO...
    AOA|AOA|AOA...
    OAA|OAA|OAA...
    --------------
    AAO|AAO|AAO...
    AOA|AOA|AOA...
    OAA|OAA|OAA...
    */
    int rc = R/3;
    int rr = R%3;
    int cc = C/3;
    int cr = C%3;

    // 行数小于三行或列数小于三列
    if(rc==0) return rr*(cc*2+cr);
    if(cc==0) return cr*(rc*2+rr);

    int ans = 0;
    // 将R*C分成4个区域
    // 1. (R/3*3)*(C/3*3):左上
    // 2. (R%3)*(C/3*3): 下测
    // 3. (R/3*3)*(C%3): 右侧
    // 4. (R%3)*(C%3): 右下
    ans += 6*rc*cc; // 任意一个3*3区域有5个座位
    ans += rr*2*cc;   //
    ans += cr*2*rc;
    ans += rr*cr==4?3:rr*cr;     //
    return ans;
}

int main() {
    string ipath = "./B-large-practice.in.txt";
    string opath = "./B-large-practice.out.txt";

    ifstream ifile(ipath);
    ofstream ofile(opath);

    if(!ifile || !ofile) {
        cout << "----> open files failed" << endl;
        return EXIT_FAILURE;
    }
    int T;
    RI(T);
    for(int t=0; t<T; t++) {
        int R, C;
        RII(R, C);
        int ans = maxSittings(R, C);
        ofile << "Case #" << t+1 <<": " << ans << endl;
    }

    ifile.close();
    ofile.close();
    return 0;
}
