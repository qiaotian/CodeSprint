/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        /* // Using recurrence
        if(!root) return root;
        TreeNode* templ;
        TreeNode* tempr;
        templ = invertTree(root->left);
        tempr = invertTree(root->right);
        root->left = tempr;
        root->right = templ;
        */
        
        // Nonrecurrence
        if(!root) return root;
        queue<TreeNode*> queueNode;
        queueNode.push(root);
        while(queueNode.size()>0){
            TreeNode* tmp = queueNode.front();
            queueNode.pop();
            // exchange subnodes
            TreeNode* depo = tmp->left;
            tmp->left = tmp->right;
            tmp->right = depo;
            // push subnodes into queue
            if(tmp->left) queueNode.push(tmp->left);
            if(tmp->right) queueNode.push(tmp->right);
        }
        return root;
    }
};

// NOTICE
/**
    Whether change the binary tree structure? YES
    Both first push subnode into queue, then change subnode or
    first push change subnode then push them into queue
    are fine!
 */
