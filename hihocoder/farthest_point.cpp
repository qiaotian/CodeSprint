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
#include <cmath> // pow
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

/**** 1st solution: BFS 20% correct
float dist(pair<int, int> cur, pair<float, float> center) {
    float x = cur.first;
    float y = cur.second;
    return sqrt(pow(x-center.first, 2)+pow(y-center.second, 2));
}

pair<int, int> farthest_point(float x, float y, float r) {
    float farthest_dist = 0.0;
    pair<int, int> ans;
    pair<float, float> center = {x, y};  //

    vector<int> dir = {-1, 0, 1, 0, -1}; // 上下左右四个方向

    queue<pair<int, int>> q;
    unordered_map<long long, pair<int, int>> visited; // 单纯从longlong不能还原出(x,y)坐标，只能用作key

    pair<int, int> start = {(int)(x+r), (int)y};

    q.push(start);
    long long pos = start.first*100000 + start.second;
    visited.insert({pos, start});
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
                visited.insert({nhx*100000+nhy, {nhx, nhy}});
                q.push(make_pair(nhx, nhy));
            }
        }
    }
    for(auto mem:visited) {
        int x = mem.second.first;
        int y = mem.second.second;
        //cout << x << " "  << y << endl;
        float distance = dist(make_pair(x, y), center);
        if(abs(distance-farthest_dist)<1E-10) {
            // 距离相等
            if(x>ans.first || (x==ans.first && y>ans.second)) ans = {x, y};
        } else {
            if(distance > farthest_dist) {
                ans = {x, y};
                farthest_dist = distance;
            }
        }
    }

    return ans;
}*/


// 2nd solution: 80% correct cases

float distanceAB(int tx, int ty, float x, float y) {
    return sqrt( (tx-x)*(tx-x) + (ty-y)*(ty-y) );
}


pair<int, int> farthest_point(float x, float y, float r) {
    float eps = 1e-6;

    // 初始化 cur_farthest_dist 和 cur_farthest_point
    float cur_farthest_dist = distanceAB((int)x, (int)y, x, y);
    pair<int, int> cur_farthest_point = {(int)x, (int)y};

	int xmax = floor(x+r);
	int xmin = ceil(x-r);
	for(int tx = xmax; tx>=xmin; tx--) {
        float d = sqrt(r*r - (tx-x)*(tx-x));
        int ymax = floor(y+d);
        int ymin = ceil(y-d);
        //for(int ty = ymin; ty<=ymax; ty++) {
        //    float dist = distanceAB(tx, ty, x, y);
        //    if(dist-cur_farthest_dist > -1*eps) {
        //        // dist <= cur_farthest_dist 时更新
        //        cur_farthest_dist = dist;
        //        cur_farthest_point = {tx, ty};
        //    }
        //}
        
        // 1. 针对 (tx, ymax) upper limitation
        float dist = distanceAB(tx, ymax, x, y);
        if(dist - cur_farthest_dist > eps) {
            cur_farthest_dist = dist;
            cur_farthest_point = {tx, ymax};
        }
            
        // 2. 针对 (tx, ymin) lower limitation
        dist = distanceAB(tx, ymin, x, y);
        if(dist - cur_farthest_dist > eps) {
            cur_farthest_dist = dist;
            cur_farthest_point = {tx, ymin};
        }
	}
    return cur_farthest_point;
}

int main(void) {
    float x, y, r;
    cin >> x >> y >> r;
    pair<int, int> ans = farthest_point(x, y, r);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}


/* 参考详解
题目大意
给定平面直角坐标系中的一个圆，求圆内（可以在边界上）离圆心最远的整点。

解题思路
本题是一道简单的计算几何类题目。

要求园内的整点，即x和y坐标均为整数的点，首先我们需要求出可能的x和y的范围。

先考虑x，显然x的上下界分别为x+r和x-r。

由于题目给定的x和r均为实数，因此x+r和x-r也可能不为整数。

所以实际上包含在圆内的x坐标上下界分别为floor(x+r)和ceil(x-r)。（floor表示下取整，ceil表示上取整）

在确定了x以后，其对应的y坐标范围也可以随之确定。如下图所示，根据勾股定理，我们即可求出d的长度。



同时可以得到对应的y坐标上下界为y+d至y-d。显然这两个值也有可能不为整数。

因此实际的y坐标范围为floor(y+d)和ceil(y-d)。

通过这两个步骤，我们就可以得到所有在圆内的点：

For tx = floor(x+r) .. ceil(x-r)
    d = sqrt(r*r - (tx-x)*(tx-x)) // 勾股定理
    For ty = floor(y+d) .. ceil(y-d)
        // (tx, ty) 是在圆内的点
        // 更新比较最优点
    End For
End For
由于本题给定的r长度最大为100,000，则可能出现在圆内的点最大可能为314亿个点。

直接枚举每个点来寻找最优值显然是不合理的，我们需要优化这个算法。

通过观察我们可以发现，在确定x坐标之后，所有的y坐标中越靠近两端的点一定比靠近中间的点离圆心远。

所以实际上我们只需要比较最两端的两个点，他们之中离圆心最远的点一定就是该x坐标下离圆心最远的点。

因此改进算法为：

ret_x = x
ret_y = y
For tx = floor(x+r) .. ceil(x-r)
    d = sqrt(r*r - (tx-x)*(tx-x)) // 勾股定理
    // 由于要求最大值，我们先考虑y坐标较大的一边
    ty = floor(y+d)
    If (tx,ty) is better than (ret_x, ret_y) Then
        ret_x = tx
        ret_y = ty
    End If
    // 再考虑坐标值较小的一边
    ty = ceil(y-d)
    If (tx,ty) is better than (ret_x, ret_y) Then
        ret_x = tx
        ret_y = ty
    End If
End For
使用改进的算法时间复杂度为O(R)，可以顺利的通过所有的测试点。

关于精度问题
在计算几何的计算中，精度问题是一个很常见的问题。

这是由于计算机存储浮点数时保留的精度有限而产生的。

即使用两个实型变量来存储同一个数字，都有可能产生误差。

因此在判定实型变量大小关系时，若直接采用=,>或<进行比较，很有可能出错。

一般常见的解决方法是设定一个极小量epsilon(一般写作eps)来辅助比较。

比如判定两个浮点数是否相等时，我们检查两个浮点数之间的差值。若差值小于eps时，我们就认为这两个浮点数相等：

equals(double x, double y):
    eps = 1e-6 // 根据题目要求的精度范围来设定eps
    If (abs(x - y) < eps) Then
        Return True
    End If
    Return false
同样，其它比较符号也需要做对应的修改，具体可以参考下表：

原符号      修正
a == b      abs(a-b) < eps
a != b      abs(a-b) > eps
a > b       a-b > eps
a >= b      a-b > -eps
a < b       a-b < -eps
a <= b      a-b < eps
*/

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
