/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(); 
        int cols = matrix[0].size();
        
        int first_col = 1;
        for(int i = 0; i< rows; i++) {
            if(matrix[i][0] == 0) first_col = 0;
            for(int j = 1; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = rows-1; i >= 0 ; i--) {
            for(int j = cols-1; j > 0; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
            }
            if(first_col == 0) matrix[i][0] = 0;
        }
    }
};

/**
 * https://leetcode.com/discuss/15997/any-shortest-o-1-space-solution
 * /
