/**
* @Author: Tian Qiao
* @Date:   2016-08-02T17:18:02+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-02T17:18:03+08:00
* @Inc: Google
* @Difficulty: Medium
*/

/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.
*/

/* 错解
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lessCnt = n-1, moreCnt = n-1;
        int r = 0, c = n-1;
        while(lessCnt+moreCnt < n*n-1) {
            if(lessCnt < k) {
                r++;
                lessCnt+=n;
                moreCnt--;
            } else {// (lessCnt >= k)
                c--;
                lessCnt--;
                moreCnt+=(n-r+1);
            }
        }
        return matrix[r][c];
    }
};*/

// binary search
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
		int mid = 0;
		while (le < ri){
			mid = (le + ri) >> 1;
			// 统计小于等于mid的元素个数(可能包含mid本省)
			int num = 0;
			for (int i = 0; i < n; i++) {
			    // 第i行小于等于mid的元素个数
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k) le = mid + 1;
			else ri = mid;
		}
		return le; // 为什么le一定是矩阵中的值
	}
};

// heap + bfs
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp = [&matrix](pair<int, int> p1, pair<int, int> p2){
            return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        que.push(make_pair(0, 0));
        int count = 1;
        while(count < k){
            auto temp = que.top();
            que.pop();
            if(temp.first+1 < matrix.size()){
                que.push(make_pair(temp.first+1, temp.second));
            }
            if(temp.first == 0 && temp.second+1 < matrix[0].size()){
                que.push(make_pair(temp.first, temp.second+1));
            }
            count++;
        }
        auto t = que.top();
        return matrix[t.first][t.second];
    }
};
