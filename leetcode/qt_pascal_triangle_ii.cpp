/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // rowIndex starts with 0, 
        // the number of rows is rowIndex+1
        vector<int> results(rowIndex+1, 0);
        results[0] = 1;
        for(int row=1; row<rowIndex+1; ++row) {
            for(int col=rowIndex; col>=1; --col) {
                results[col] += results[col-1];
            }
        }
        return results;
    }
};

/***
 * Pascal Triangle
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 * 1 5 10 10 5 1
 * ......
 * 
 * /
