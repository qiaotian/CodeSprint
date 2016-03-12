class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int all = m * n;
        // k:层号，count:当前已经访问的元素数目
        // i:行号，j:列号
        int i = 0, j = 0, k = 0, count = 0;

        while(count < all) {
            // left to right
            if(j >= n-k) return res;
            while(j < n-k) {res.push_back(matrix[i][j++]); count++;}
            j--; i++; // recover j and move down
            // top to buttom
            if(i >= m-k) return res;
            while(i < m-k) {res.push_back(matrix[i++][j]); count++;}
            i--; j--; // recover i and move left;
            // right to left
            if(j < k) return res;
            while(j >= k) {res.push_back(matrix[i][j--]); count++;}
            j++; i--; // recover j and move up
            // buttom to up
            if(i <= k) return res;
            while(i > k) {res.push_back(matrix[i--][j]); count++;}
            i++; j++; // recover i and move right
            k++;
        }

        return res;
    }
};
