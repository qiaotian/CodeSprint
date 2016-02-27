// 1st solution (12ms, beats 1%)
/*
class Solution {
private:
    int helper(int start, int end) {
        if(start > end) return 0;
        if(start == end) return 1;
        int sum = 0;
        for(int i = start; i <= (end+start-1)/2; i++) {
            // select i as the root
            // use left side node as root, double as its symetry
            sum += 2 * max(1, helper(start, i-1)) * max(1, helper(i+1, end));
        }
        // use the middle number as the root
        if((end-start+1)%2) 
            sum += max(1, helper(start, (end+start)/2-1)) * max(1, helper((end+start)/2+1, end));
        return sum;
    }
public:
    int numTrees(int n) {
        return helper(1, n);
    }
};
*/

/**
 * Taking 1~n as root respectively:
 *      1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
 *      2 as root: # of trees = F(1) * F(n-2) 
 *      3 as root: # of trees = F(2) * F(n-3)
 *      ...
 *      n-1 as root: # of trees = F(n-2) * F(1)
 *      n as root:   # of trees = F(n-1) * F(0)
 *
 * So, the formulation is:
 *      F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)
 */

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for(int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};


/**
 * 1st solution
 * 
 * 1, 2, 3, 4, ..., n
 * 分别以某一数字i为根节点，那么数组被分成两个部分left和right
 * 那么以i为根节点的所有BST数目为BST(left)*BST(right)
 * 因为BST(left)或BST(right)有可能为零，所以要取max(1, BST(left))*max(1, BST(right))
 * 
 * 仅仅这样，当n>=19会TLE，需要减少计算量
 * 我们发现，left*right = right * left的数目
 * 因此，我们只需要计算以1到中点产生的所有BST，然后乘2即可。
 * 注意，当n为奇数时，中间节点单独计算。
 * 
 * 2nd solution
 * 
 * 
 * /
