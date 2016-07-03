/**
* @Author: Tian Qiao
* @Date:   2016-07-03T14:47:31+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T15:27:09+08:00
* @Inc: Google+MS+Snapchat
*/

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

________________________________________________________________________________

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    long long util(TreeNode* root, double target) {
        // 此处直接返回INT32_MAX会造成错误，因为target可能为INT32_MAX*1.0
        if(!root) return INT64_MAX;
        long long m = root->val;
        long long l = util(root->left, target);
        long long r = util(root->right, target);

        double delta_m = abs(m-target);
        double delta_l = abs(l-target);
        double delta_r = abs(r-target);

        if(delta_m<=delta_l && delta_m<=delta_r) return m;
        if(delta_l<=delta_m && delta_l<=delta_r) return l;
        if(delta_r<=delta_m && delta_r<=delta_l) return r;
        return 0;
    }

    int closestValue(TreeNode* root, double target) {
        return (int)util(root, target);
    }
};

/* Special Cases
Input:
[0]
2147483648.0
Output:
2147483647
Expected:
0*/

/*
Input:
[2147483647]
0.0
Output:
-1
Expected:
2147483647
*/
