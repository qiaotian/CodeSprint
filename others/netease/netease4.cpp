#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string line;
    while(getline(cin, line)) {
        int n, k;
        istringstream iss(line);
        iss >> n >> k;
        getline(cin, line);
        istringstream iss2(line);
        vector<int> requests(n, 0);
        vector<vector<int>> cenema(k, vector<int>(k, 0)); //0表示空
        for(int i=0; i<n; i++) {
            int tmp;
            iss2 >> tmp;
            requests[i] = tmp;
        }

        vector<pair<int, int>> filled(k, pair<int, int>(-1, -1));
        for(int i=0; i<n; i++) {
            // 处理request[i]
            int mindist = INT32_MAX;
            int x = INT32_MAX, yl = INT32_MAX, yr = -1; // 行号和起止点
            int tickets = requests[i];
            if(tickets > k) { cout << "-1" << endl; continue; }
            for(int row = 0; i<k; i++) {
                int start = filled[row][0];
                int end   = filled[row][1];
                if(start == -1) {
                    // 当前行为空
                    int curx = row;
                    int curyl = (k+1)/2-tickets/2;
                    int curyr = curyl+tickets-1;
                    int curdist = 0;
                    for(int k = yl; k<=rl; k++) {
                        curdist += abs((k+1)/2-curx)+abs((k+1)/2-k);
                    }
                    if(curdist < mindist || (curdist==mindist && row<=(k+1)/2)) {
                        mindist = curdist;
                        x = row;
                        yl = curyl;
                        yr = curyr;
                    }
                } else {
                    if((start<tickets) || (k-end<tickets)) continue;
                    if(start>tickets) {
                        // 放左边
                        int curx = row;
                        int curyl = start-tickets;
                        int curyr = start-1;
                        int curdist = 0;
                        for(int k = yl; k<=rl; k++) {
                            curdist += abs((k+1)/2-curx)+abs((k+1)/2-k);
                        }
                        if(curdist < mindist ||
                           (curdist==mindist && abs(curx-(k+1)/2))< abs(x-(k+1)/2) ||
                           (curdist==mindist && abs(curx-(k+1)/2))==abs(x-(k+1)/2) && curx <= (k+1)/2 ||
                           (curdist==mindist && curx == x && curyl<yl)) {
                            mindist = curdist;
                            x = row;
                            yl = curyl;
                            yr = curyr;
                        }
                    }
                    if(k-end>=tickets) {
                        // 放右边
                        int curx = row;
                        int curyl = end+1;
                        int curyr = end+tickets;
                        int curdist = 0;
                        for(int k = yl; k<=rl; k++) {
                            curdist += abs((k+1)/2-curx)+abs((k+1)/2-k);
                        }
                        if(curdist < mindist ||
                           (curdist==mindist && abs(curx-(k+1)/2))< abs(x-(k+1)/2) ||
                           (curdist==mindist && abs(curx-(k+1)/2))==abs(x-(k+1)/2) && curx <= (k+1)/2 ||
                           (curdist==mindist && curx == x && curyl<yl)) {
                            mindist = curdist;
                            x = row;
                            yl = curyl;
                            yr = curyr;
                        }
                    }
                }
            }
            filled[x][0] = min(filled[x][0], curyl);
            filled[x][1] = max(filled[x][1], curyr);

            // 输出
            cout << x << yl << yr << endl;
        }
    }
    return 0;
}
