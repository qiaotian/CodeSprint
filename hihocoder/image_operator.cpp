/*
Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
在图像处理的技术中，经常会用到算子与图像进行卷积运算，从而达到平滑图像或是查找边界的效果。

假设原图为H × W的矩阵A，算子矩阵为D × D的矩阵Op，则处理后的矩阵B大小为(H-D+1) × (W-D+1)。其中：

B[i][j] = ∑(A[i-1+dx][j-1+dy]*Op[dx][dy]) | (dx = 1 .. D, dy = 1 .. D), 1 ≤ i ≤ H-D+1, 1 ≤ j ≤ W-D+1

给定矩阵A和B，以及算子矩阵的边长D。你能求出算子矩阵中每个元素的值吗？

Input
第1行：3个整数，H, W, D，分别表示原图的高度和宽度，以及算子矩阵的大小。5≤H,W≤60，1≤D≤5，D一定是奇数。

第2..H+1行：每行W个整数，第i+1行第j列表示A[i][j]，0≤A[i][j]≤255

接下来H-D+1行：每行W-D+1个整数，表示B[i][j]，B[i][j]在int范围内，可能为负数。

Output
第1..D行：每行D个整数，第i行第j列表示Op[i][j]。

Sample Input
5 5 3
1 6 13 10 3
13 1 5 6 15
8 2 15 0 12
19 19 17 18 18
9 18 19 5 17
22 15 6
35 -36 51
-20 3 -32

Sample Output
0 1 0
1 -4 1
0 1 0
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> convolution(vector<vector<int>>& A, vector<vector<int>>& op) {
    int rows = A.size()-op.size()+1;
    int cols = A[0].size()-op[0].size()+1;
    int D = op.size();

    vector<vector<int>> ans(rows, vector<int>(cols, 0));

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
           int tmp = 0;
           for(int m=0; m<D; m++) {
               for(int n=0; n<D; n++) {
                   tmp+=A[i+m][j+n]*op[m][n];
               }
           }
           ans[i][j] = tmp;
        }
    }
    return ans;
}

int main() {
	int H, W, D;
	cin >> H >> W >> D;
	vector<vector<int>> A;
    vector<vector<int>> op;
    
    for(int i=0; i<H; i++) {
        vector<int> line;
        for(int j=0; j<W; j++) {
            int tmp;
            cin >> tmp;
            line.push_back(tmp);
        }
        A.push_back(line);
    }
    for(int i=0; i<D; i++) {
        vector<int> line;
        for(int j=0; j<D; j++) {
            int tmp;
            cin >> tmp;
            line.push_back(tmp);
        }
        op.push_back(line);
    }

    vector<vector<int>> ans = convolution(A, op);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[0].size(); j++) {
            cout << ans[i][j];
            if(j!=ans[0].size()-1) cout << " ";
        }
        cout << endl;
    }
}
