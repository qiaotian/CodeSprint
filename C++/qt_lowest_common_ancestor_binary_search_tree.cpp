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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left, p, q);
        if (p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right, p, q);
        return root;

        /*
        TreeNode* tmp = root;
        while((tmp->val-p->val)*(tmp->val-q->val)>0) {
            tmp = tmp->val-p->val>0?tmp->left:tmp->right;
        }
        return tmp;
        */
    }
};

// NOTICE
/**
 * BST
 * value in right subtree must be bigger than value in left subtree,
 * therefore there is no duplicated values in BST.
 * /
