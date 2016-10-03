#include <iostream>
#include <vector>

using namespace std;

vector<int> dir = {0, 1, 0, -1, -1, 1, 1, -1, 0};

void util(vector<vector<char>>& grid, int x, int y, int t) {
    grid[x][y] = t==0?'*':'o';
    for(int d=0; d<8; d++) {
        //cout << "d = " << d << endl;
        // 8个方向
        vector<pair<int, int>> positions;
        int xx = x+dir[d];
        int yy = y+dir[d+1];
        while(xx>=0 && xx<8 && yy>=0 && yy<8) {
            if(grid[xx][yy]=='.') break;

            if(grid[xx][yy]==(t==0?'o':'*')) {
                positions.push_back({xx, yy});
                xx = xx+dir[d];
                yy = yy+dir[d+1];
                //if(d==2) cout << xx << " " << yy <<endl;
            } else {
                for(auto p:positions) {
                    grid[p.first][p.second] = (t==0?'*':'o');
                }
                break;
            }
        }
    }
}

int main() {
	int cnt;
    cin >> cnt;
    vector<vector<char>> grid(8, vector<char>(8, '.'));
    cout << "cases is " << cnt << endl;
    for(int it=0; it<cnt; it++) {
    	for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                cin >> grid[i][j];
            }
        }

        /*cout << endl;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;*/

        int steps;
        cin >> steps;
        // 走steps步棋
        for(int k=0; k<steps; k++) {
            int x, y, t;
            cin >> x >> y >> t;
            util(grid, x, y, t);
            /*
            cout << endl;
            for(int i=0; i<8; i++) {
                for(int j=0; j<8; j++) {
                    cout << grid[i][j];
                }
                cout << endl;
            }
            cout << endl;*/
        }

        //cout << "Hello" << endl;
        // 统计黑白子数目
        int black = 0;
        int white = 0;
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(grid[i][j]=='*') black++;
                if(grid[i][j]=='o') white++;
            }
        }
        cout << black << " " << white << endl;
    }
    return 0;
}
