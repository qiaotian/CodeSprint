/*
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 1st (Slow)
        vector<vector<int>> res;
        if(numRows<1) return res;

        for(int i=0; i<numRows; i++) {
            vector<int> row(i+1, 1);
            if(i<2) {
                res.push_back(row); // crash down why???
                continue;
            }
            vector<int> &preRow = res[i-1];
            for(int j=1; j<i; j++) {
                row[j] = preRow[j]+preRow[j-1];
            }
            res.push_back(row);
        }
        return res;
        
        /* 2nd (Optimised)
        vector<vector<int>> res;
        for(auto i=0;i<numRows;++i)
        {
            res.push_back(vector<int>(i+1,1));
            for(auto j=1; j<i; ++j) 
                res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;*/
    }
};
