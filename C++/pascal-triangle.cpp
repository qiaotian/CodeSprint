class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 1st Solution
        vector<vector<int>> res;
        if(numRows<1) return res;

        for(int i=0; i<numRows; i++) {
            vector<int> row(i+1, 1);
            if(i<2) {
                res.push_back(row);
                continue;
            }
            vector<int> &preRow = res[i-1];
            for(int j=1; j<i; j++) {//pay attention to the upper boundary of j
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

/***
 * 1st Solution has the same time complexity wih 2nd Solution,
 * but 2nd could be more concise;
 * /
