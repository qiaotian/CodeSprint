/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
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
    bool isSymmetric(TreeNode* root) {
        // Solution 1
        /*
        if(!root) return true;
        
        queue<TreeNode*> ql;
        queue<TreeNode*> qr;
        
        TreeNode *nl;
        TreeNode *nr;
        
        ql.push(root->left);
        qr.push(root->right);
        
        while(!ql.empty() && !qr.empty()) {
            nl = ql.front();
            nr = qr.front();
            
            ql.pop();
            qr.pop();
            
            if(!nl && !nr) continue;
            if(!nl || !nr) return false;
            if(nl->val != nr->val) return false;
            
            ql.push(nl->left);
            ql.push(nl->right);
            qr.push(nr->right);
            qr.push(nr->left);
        }
        return true;
        */
        //Solution 2
        /*
        if(!root) return true;
        
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        
        while(!que.empty()) {
            TreeNode* left = que.front();
            que.pop();
            TreeNode* right = que.front();
            que.pop();
            if(!left && !right) continue;
            if(!left || !right) return false;
            if(left->val != right->val) return false;
            que.push(left->left);
            que.push(right->right); // the sequence of node pushed here differs from  that of Solution 1
            que.push(left->right);
            que.push(right->left);
        }
        return true;
        */
        // Solution 3
        if(!root) return true;
        return util(root->left, root->right);
    }
    
    bool util(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        return util(left->left, right->right)&&util(left->right, right->left);
    }
};

/**
 * Solution 1 use two queue for iteration
 * Solution 2 use one queue for iteration
 * Solution 3 use recursion method
 * /
