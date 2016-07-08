/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T00:03:18+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-09T02:41:49+08:00
*/



Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.



// beat 30%, bad
class Solution {
public:
    int ans = 0;
    // flag: visited or not
    // start: the starting point where we find the m and n steps
    void dfs(vector<vector<bool>>& flag, int start, int m, int n) {
        if(n<0) return; //长度超标 结束
        if(m<=0 && n>=0) ans++;
        for(int i=0; i<9; i++) {
            int row = i/3, col = i%3; // 待选目标点坐标
            if(flag[row][col]) continue; //访问过则跳过

            if(abs(start/3-row)==2 && abs(start%3-col)==2 && !flag[1][1]) continue;
            if(abs(start/3-row)==2 && abs(start%3-col)==0 && !flag[(start/3+row)/2][col]) continue;
            if(abs(start/3-row)==0 && abs(start%3-col)==2 && !flag[row][(start%3+col)/2]) continue;

            // 访问该节点
            flag[row][col] = true;
            dfs(flag, i, m-1, n-1);
            flag[row][col] = false;
        }
    }
    int numberOfPatterns(int m, int n) {
        if(m==1 && n==1) return 9;
        vector<vector<bool>> flag(3, vector<bool>(3, false));
        //for(int i=0; i<9; i++) {
            //考虑到对称性，无需遍历所有9个出发点
            flag[0][0] = true;
            dfs(flag, 0, m-1, n-1);
            flag[0][0] = false;

            flag[0][1] = true;
            dfs(flag, 1, m-1, n-1);
            flag[0][1] = false;

            ans *=4;

            flag[1][1] = true;
            dfs(flag, 4, m-1, n-1);
            flag[1][1] = false;
        //}
        return ans;
    }
};
