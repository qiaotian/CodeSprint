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

using namespace std;

float dist(pair<int, int>& start, pair<float, float>& center) {
    return sqrt(pow(start.first-center.first, 2)+pow(start.second-center.second, 2));
}

pair<int, int> farthest_point(float x, float y, float r) {
    pair<int, int> ans = {(int)x, (int)y}; //
    pair<float, float> center = {x, y}; // 
    
    int new_x = (int)(x+0.5);
    int new_y = (int)(y+0.5);

    pair<int, int> dir = {0, 0};        // 最远点所在大致方位
    dir.first = new_x<x?-1:1;
    dir.second = new_y<y?-1:1;

    pair<int, int> run = {new_x+dir.first*r, new_y};
    while(run.first != new_x) {
        float tmp = dist(run, center);
        if(dist(run, center)>r) run.first-=dir.first;
        else {
            if(tmp > dist(ans, center)) ans = run;
            run.second+=dir.second;
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





