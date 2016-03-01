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
 * 2. 1st solution (Top-Down DP) 三角形较大时，使用dps调用层次过深，容易超时
 * 3. 2nd solution (Buttom-Up DP)由下而上，所有节点只需遍历一遍即可求解，典型DP思想
 * 
 * Tip:(Top-Down and Bottom-Up Dp) What I like about this problem even more is that the difference between 'top-down' and 'bottom-up' DP can be 'literally' pictured in the input triangle. For 'top-down' DP, starting from the node on the very top, we recursively find the minimum path sum of each node. When a path sum is calculated, we store it in an array (memoization); the next time we need to calculate the path sum of the same node, just retrieve it from the array. However, you will need a cache that is at least the same size as the input triangle itself to store the pathsum, which takes O(N^2) space. With some clever thinking, it might be possible to release some of the memory that will never be used after a particular point, but the order of the nodes being processed is not straightforwardly seen in a recursive solution, so deciding which part of the cache to discard can be a hard job.

'Bottom-up' DP, on the other hand, is very straightforward: we start from the nodes on the bottom row; the min pathsums for these nodes are the values of the nodes themselves. From there, the min pathsum at the ith node on the kth row would be the lesser of the pathsums of its two children plus the value of itself 
 */
