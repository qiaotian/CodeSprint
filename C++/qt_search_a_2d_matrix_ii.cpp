// hard (196ms, beats 94%)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] < target) i++;
            else if (matrix[i][j] > target) j--;
            else return true;
        }
        return false;
    }
};
/**
 * 这道题目和之前的题目不同点在于行末尾元素值和
 * 下一行第一个元素值之间没有递增关系，所以不能
 * 做到先确定行再确定列。
 * /
