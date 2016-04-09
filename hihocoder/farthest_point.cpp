/*

Time Limit:5000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
Given a circle on a two-dimentional plane.
Output the integral point in or on the boundary of the circle which has the largest distance from the center.

Input
One line with three floats which are all accurate to three decimal places, indicating the coordinates of the center x, y and the radius r.
For 80% of the data: |x|,|y|<=1000, 1<=r<=1000
For 100% of the data: |x|,|y|<=100000, 1<=r<=100000

Output
One line with two integers separated by one space, indicating the answer.
If there are multiple answers, print the one with the largest x-coordinate.
If there are still multiple answers, print the one with the largest y-coordinate.

Sample Input
1.000 1.000 5.000
Sample Output
6 1

*/

#include <iostream>
#include <cmath> // pow会用到
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> center = {0, 0};

float dist(pair<int, int>& start, pair<float, float>& center) {
    float x = start.first;
    float y = start.second;
    return sqrt(pow(x-center.first, 2)+pow(y-center.second, 2));
}

/*
pair<int, int> farthest_point(float x, float y, float r) {
    pair<int, int> ans = {(int)x, (int)y}; //
    pair<float, float> center = {x, y};    // 
    
    int new_x = (int)(x+(x>=0?0.5:-0.5));
    int new_y = (int)(y+(y>=0?0.5:-0.5));

    //cout << new_x << " " << new_y << endl;

    pair<int, int> dir = {0, 0};        // 最远点所在大致方位（正方向）
    dir.first = new_x<x?-1:1;
    dir.second = new_y<y?-1:1;
    //cout << dir.first << " " << dir.second << endl;

    pair<int, int> run = {new_x+dir.first*r, new_y};
    //cout << run.first << " " << run.second << endl;
    while(1) {
        float tmp = dist(run, center);
        if(tmp > r) run.first-=dir.first;
        else {
            if(tmp > dist(ans, center)) ans = run;
            run.second+=dir.second;
        }
        if(run.first == new_x) break;
        //cout << run.first << run.second << endl;
    }
    return ans;
}
*/

vector<int> dir = {-1, 0, 1, 0, -1};

pair<int, int> farthest_point(float x, float y, float r) {
    float farthest_dist = INT_MIN;
    pair<int, int> ans;
    //pair<float, float> center = {x, y};
    center.first = x;
    center.second = y;
    queue<pair<int, int>> q;
    unordered_set<long long> visited;
    pair<int, int> start = {(int)(x+r), (int)y};
    q.push(start);
    long long pos = start.first*100000 + start.second;
    visited.insert(pos);
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++) {
            int nhx = x+dir[i];
            int nhy = y+dir[i+1];
            float distance = dist(make_pair(nhx, nhy), center);
            // 只考虑与center距离介于[r-1, r]的所有整数位置
            if(distance>r || distance<r-1) continue;
            if(visited.find(nhx*100000+nhy)!=visited.end()) continue;
            else {
                visited.insert(nhx*100000+nhy);
                q.push(make_pair(nhx, nhy));
            }
        }
    }
    for(auto num:visited) {
        int x = num/100000;
        int y = num%100000;
        float distance = dist(make_pair(x, y), center);
        if(distance > farthest_dist) {
            ans = {x, y};
            farthest_dist = distance;
        }
    }
    return ans;
}


int main(void) {
    float x, y, r;
    cin >> x >> y >> r;
    pair<int, int> ans = farthest_point(x, y, r);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}





