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
    // 返回每一层最后一个节点（BFS）
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int count = que.size();
            for(int i = 0; i < count; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(i == count-1) res.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return res;
    }
};
