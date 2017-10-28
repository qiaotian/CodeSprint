/**
 * @Author: qiao
 * @Date:   2017-08-24T00:27:17+08:00
 * @Email:  qiaotian@me.com
 * @Last modified by:   qiao
 * @Last modified time: 2017-08-24T23:39:15+08:00
 * @License: MIT
 * @Copyright: qiaotian
 */

/*

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input:

        1
      /   \
     3     2
    / \     \
   5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input:

       1
      /
     3
    / \
   5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input:

       1
      / \
     3   2
    /
   5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input:

       1
      / \
     3   2
    /     \
   5       9
  /         \
 6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.

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

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *end = root; // point to the last node who has child
        int res = 1;
        int cur = 0;
        while(!q.empty()) {
            x = q.pop();
            if(end->left == x || end->right == x) {
                if
            }
            cur++;
            res = max(res, cur);
        }
    }
};

int main() {
    Solution sln = new Solution();
    sln.widthOfBinaryTree();
    delete sln;
    return 0;
}
