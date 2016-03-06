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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> que;
        que.push(root);
        
        bool left2right = true;
        while(!que.empty()) {
            int count = que.size();
            vector<int> layer;

            for(int i=0; i<count; i++) {
                TreeNode* node = que.front();
                que.pop();
                layer.push_back(node->val);
                
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                
                if(i == count-1) res.push_back(left2right?layer:vector<int>(layer.rbegin(), layer.rend()));
            }
            left2right = !left2right;
        }
        
        return res;
    }
};