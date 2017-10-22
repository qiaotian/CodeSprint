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
    /*
    int dp(vector<int>& cost, int pos) {
        if(pos >= cost.size()) return 0;
        if(pos+1 >= cost.size()) return cost[pos];
        if(pos+2 >= cost.size()) return max(cost[pos], cost[pos+1]);
        return max(cost[pos] + dp(cost, pos+2), dp(cost, pos+1));
    }
public:
    ----思路错误----
    仅仅考虑到节点层号不相邻即可
    没有考虑层号相邻但不同子树的情况
    int rob(TreeNode* root) {
        if(!root) return 0;
        vector<int> cost;
        queue<TreeNode*> que;
        que.push(root);

        // prepare the cost for every layer
        while(!que.empty()) {
            int cur = 0;
            int len = que.size();
            for(int i = 0; i < len; i++) {
                TreeNode* node = que.front();
                que.pop();
                cur += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            cost.push_back(cur);
        }

        // find the maximum money
        return dp(cost, 0);
    }
    */

public:
    // (TLE)
    /*
    int util(TreeNode* root, bool rootAvail) {
        if(!root) return 0;

        if(rootAvail) {
            int cost1 = root->val+util(root->left, false)+util(root->right, false);
            int cost2 = util(root->left, true) + util(root->right, true);
            return max(cost1, cost2);
        } else {
            return util(root->left, true) + util(root->right, true);
        }
    }
    int rob(TreeNode* root) {
        return util(root, true);
    }
    */

    // 2nd solution (1340ms so bad)
    /*
    int util(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        int cost1 = root->val, cost2 = 0;
        if(root->left) {
            cost1 += util(root->left->left)+util(root->left->right);
            cost2 += util(root->left);
        }
        if(root->right) {
            cost1 += util(root->right->left)+util(root->right->right);
            cost2 += util(root->right);
        }
        return max(cost1, cost2);
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        return util(root);
    }
    */

    // 3rd solution (12ms very good)

    int rob(TreeNode* root)
    {
        // mt: rob root
        // ms: don't rob root
        int mt, ms;
        rob(root, mt, ms);
        return max(mt, ms);
    }

    void rob(TreeNode* node, int& mt, int& ms)
    {
        mt = ms = 0;
        if (!node) return;
        // mtl 抢左子树根节点
        // mtr 抢右子树根节点
        // msl 不抢左子树根节点
        // msl 不抢右子树根节点
        int mtl, mtr, msl, msr;
        rob(node->left, mtl, msl);
        rob(node->right, mtr, msr);

        mt = msl + msr + node->val;
        ms = max(mtl, msl) + max(mtr, msr);
        return;
    }
};

// 两种方案：1. 偷root 2. 不偷root
// 没有父子或兄弟关系的房子都可以偷
// 并不是广度优先搜索
// 这三种solution的思想是一致的，但运行时间差距很大
// 以2nd和3rd为例相差100倍
