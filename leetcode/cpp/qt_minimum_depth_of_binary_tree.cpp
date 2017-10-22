/*
 Given a binary tree, find its minimum depth.

 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        // 1st Solution (BFS)
        /*
        int depth = 0;
        if(!root) return depth;
        queue<TreeNode*> que;
        que.push(root);
        int curr = 1; // the number of nodes in current layer
        int next = 0; // the number of nodes in next layer
        while(!que.empty()) {
            TreeNode *tmp = que.front();
            que.pop();
            curr--;
            
            if(tmp->left) {que.push(tmp->left), next++;}
            if(tmp->right) {que.push(tmp->right), next++;}
            if(!tmp->left && !tmp->right) return ++depth;
            
            if(curr==0) { // all the nodes in current layer have been scanned
                curr = next;
                next = 0;
                depth++;
            }
        }
        */
        // 2nd Solution (Recursive)
        /*
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left), minDepth(root->right));
        */
        
        // 3rd Solution (BFS)
        if (root == NULL) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int layer = 0;
        while (!Q.empty()) {
            layer++;
            int k = Q.size();
            for (int j=0; j<k; j++) {
                TreeNode* rt = Q.front();
                if (rt->left) Q.push(rt->left);
                if (rt->right) Q.push(rt->right);
                Q.pop();
                if (rt->left==NULL && rt->right==NULL) return layer;
            }
        }
    }
};

/***
 * Both 1st sln and 2nd sln use the BFS, 
 * but differ in looping.
 * The 1st use two flags curr and next to mark the nodes number, 
 * while the 2nd use a 'for' loop in 'while' loop, which could be easier to read.
 * 
 * /
