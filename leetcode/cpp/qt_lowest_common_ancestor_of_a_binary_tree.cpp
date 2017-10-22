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
        //迭代中使用lowestCommonAncestor不是找最低公共祖先，而是找到p或q并返回p或q
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //if(!left) return right;
        //else if(!right) return left;
        //else return root;
        return !left ? right : !right ? left : root;
    }
};

/*class Solution {
    vector<TreeNode*> tracker;
    vector<TreeNode*> pTracker;
    vector<TreeNode*> qTracker;
public:
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return;

        tracker.push_back(root);
        if(root->val == p->val) pTracker = tracker;
        if(root->val == q->val) qTracker = tracker;

        if(pTracker.empty() && qTracker.empty()) return; // both found

        dfs(root->left, p, q);
        dfs(root->right, p, q);

        tracker.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);

        int lenp = pTracker.size();
        int lenq = qTracker.size();
        for(int i = 0; i < lenp && i < lenq; i++) {
            if(pTracker[i]->val != qTracker[i]->val){
                return pTracker[i-1];
            }
        }
        return root;
    }
};*/
