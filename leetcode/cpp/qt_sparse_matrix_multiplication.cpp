/**
* @Author: Tian Qiao
* @Date:   2016-07-04T17:08:20+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-04T18:17:39+08:00
* @Inc: LinkedIn, Facebook
* @Difficulty: Medium
*/


———————————————————————————————————————————————————————————————————————————————
Given two sparse matrices A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.
Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
——————————————————————————————————————————————————————————————————————————————-

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {

        vector<vector<int>> ans;

        if(A.empty()||A[0].empty()) return ans;
        if(B.empty()||B[0].empty()) return ans;

        int rowsA = A.size(), colsA = A[0].size();
        int rowsB = B.size(), colsB = B[0].size();

        ans.resize(rowsA, vector<int>(colsB, 0));
        vector<pair<int, int>> sa; // sa中非空点集的集合
        unordered_map<int, vector<pair<int, int> > > sb; // 行号到该行非零点集的字典
        for(int i=0; i<rowsA; i++) {
            for(int j=0; j<colsA; j++) {
                if(A[i][j]) sa.push_back({i, j});
            }
        }
        for(int i=0; i<rowsB; i++) {
            vector<pair<int, int>> dots;
            for(int j=0; j<colsB; j++) {
                if(B[i][j]) dots.push_back({i, j});
            }
            sb.insert({i, dots});
        }
        for(auto i:sa){
            int r = i.first;
            int c = i.second; // A的第c列的元素与B的第c行元素相乘
            for(auto pos:sb[c]) {
                ans[r][pos.second]+=A[r][c]*B[pos.first][pos.second];
            }
        }
        return ans;

        /* Other's
        int am = A.size();//2
        int bm = B.size();//3

        int an = A[0].size();//3
        int bn = B[0].size();//3 2*3 3*3 => 2*3
        vector<vector<int>> result(am,vector<int>(bn,0));
        vector<vector<int>> A_non_zero(am);
        vector<vector<int>> B_non_zero(bn);

        for(int i=0;i<am;i++)
            for(int j=0;j<an;j++)
                if(A[i][j]) A_non_zero[i].push_back(j);

        for(int j=0;j<bn;j++)
            for(int i=0;i<bm;i++)
                if(B[i][j]) B_non_zero[j].push_back(i);

        for(int i=0;i<am;i++) {
            for(int j=0;j<bn;j++){
                int m=0,n=0;
                    while(m<A_non_zero[i].size() && n<B_non_zero[j].size()){
                    int idx_A = A_non_zero[i][m];
                    int idx_B = B_non_zero[j][n];
                    if(idx_A == idx_B){
                        result[i][j]+= (A[i][idx_A]*B[idx_B][j]);
                        m++;
                        n++;
                    }
                    else if(idx_A > idx_B)
                        n++;
                    else
                        m++;
                }
            }
        }
        return result;*/
    }
};
