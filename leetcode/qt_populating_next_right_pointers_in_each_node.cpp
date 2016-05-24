/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> que;
        que.push(root);
        while(!que.empty()) {
            int n = que.size();
            for(int i = 0; i < n; i++) {
                TreeLinkNode *curr = que.front();
                que.pop();
                if(i < n-1) curr->next = que.front();
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
        }
    }
};

/**
 * BFS
 * so easy
 * /
