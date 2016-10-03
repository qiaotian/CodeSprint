#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n, p;
    cin >> m >> n >> p;
    vector<vector<vector<int>>> bigcube;
    bigcube.resize(m, vector<vector<int>>(m, vector<int>(m, 0)));
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<m; k++) {
                cin >> bigcube[i][j][k];
                bigcube[i][j][k] = (bigcube[i][j][k]*2)%p;
            }
        }
    }
    vector<vector<vector<int>>> smallcube;
    for(int t=0; t<n; t++) {
        int len;
        cin >> len;
        smallcube.resize(len, vector<vector<int>>(len, vector<int>(len, 0)));
        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                for(int k=0; k<len; k++) {
                    cin >> smallcube[i][j][k];
                }
            }
        }
        //
        for(int i=0; i<m-len+1; i++) {
            for(int j=0; j<m-len+1; j++) {
                for(int k=0; k<m-len+1; k++) {
                    bool ismatch = true;
                    for(int x=0; x<len; x++) {
                        for(int y=0; y<len; y++) {
                            for(int z=0; z<len; z++) {
                                // smallcube[i][j][k];
                                if(bigcube[i][j][k]!=smallcube[x][y][z]) {
                                    ismatch = false;
                                    break;
                                }
                            }
                            if(!ismatch) break;
                        }
                        if(!ismatch) break;
                    }
                    // output the result
                    if(ismatch) cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }

    return 0;
}
