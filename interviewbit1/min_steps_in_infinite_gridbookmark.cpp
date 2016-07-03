/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-30T21:20:15+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-30T21:21:43+08:00
* @License: Free License
*/

/******
You are in an infinite 2D grid where you can move in any of the 8 directions :

(x,y) to
    (x+1, y),
    (x-1, y),
    (x, y+1),
    (x, y-1),
    (x-1,y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Example :
Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.
*/


// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int ans = 0;
    int len = X.size();
    if(len<2) return 0;

    pair<int, int> cur = {X[0],Y[0]};
    for(int i=1; i<len; i++) {
        int delta_x = abs(X[i]-cur.first);
        int delta_y = abs(Y[i]-cur.second);
        ans += max(delta_x, delta_y);
        cur.first = X[i];
        cur.second = Y[i];
    }
    return ans;
}
