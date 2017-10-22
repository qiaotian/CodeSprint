/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
        if(!(p||q)) // return true if both p & q not exist
            return true;  
        else if((!p&&q)||(p&&!q)) 
            return false;
        if(p->val==q->val) 
            return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
        else 
            return false;
        */
        if(p==NULL || q==NULL) return p==q; // excepet the condition that both are not null
        else return (p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
