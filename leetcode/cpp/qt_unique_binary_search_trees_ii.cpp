/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T23:50:06+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-13T00:36:58+08:00
* @Inc: Snapchat
*/

/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 上一题求互异BST的数目，该题则是求出所有BST
class Solution {
public:
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> ans;
        if(start > end) {
            ans.push_back(NULL);
            return ans;
        }
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> ll = helper(start, i-1);
            vector<TreeNode*> rr = helper(i+1, end);
            for(auto l:ll) {
                for(auto r:rr) {
                    // 必须每一次都实例一个root
                    // 否则，虽然每次ans.push_back(root)
                    // 本质上入栈的只是个指针，这些root共同指向
                    // 同一块内存。虽然有多个root指针，每一次修
                    // 改root指针，都只是修改同一块内存。
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n<1) return vector<TreeNode*>();
        return helper(1, n);
    }
};
