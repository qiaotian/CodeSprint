// TLE
/*
class Solution {
private:
    int dps(vector<vector<int>>& triangle, int i, int j) {
        // i为三角形根节点层号0-based address
        // j为三角形根节点列号0-based address
        if(i == triangle.size()-1) return triangle[i][j];
        return triangle[i][j] + min(dps(triangle, i+1, j), dps(triangle, i+1, j+1));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return dps(triangle, 0, 0);
    }
};
*/

// 2nd solution (DP)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        if(n == 1) return triangle[0][0];
        
        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < i+1; j++)
                triangle[i][j] = min(triangle[i][j]+triangle[i+1][j], 
                                     triangle[i][j]+triangle[i+1][j+1]);
        }
        return triangle[0][0];
    }
};

/**
 * WARNING
 * 1. 由于每层无序，所以不能用贪婪算法求解，注意到这点，本题没有难度
 * 2. 1st solution 三角形较大时，使用dps调用层次过深，容易超时
 * 2. 2nd solution 由下而上，所有节点只需遍历一遍即可求解，典型DP思想
 * /
