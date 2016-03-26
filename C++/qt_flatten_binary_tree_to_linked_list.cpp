// 先将左子树flatten，然后在将右子树flatten
// 最后将根节点、左子树、右子树拼接即可
// 注意: flatten左子树后要将子树的最后一个节点返回，否则无法完成拼接

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    void util(TreeNode* root, TreeNode* tail) {
        TreeNode* ll = root->left;
        TreeNode* rr = root->right;
        TreeNode* lend = NULL;
        TreeNode* rend = NULL;

        root->left = root->right = NULL;
        tail = root;
        if(!ll && !rr) {
            return;
        } else if(ll && !rr) {
            util(ll, lend);
            root->right = ll;

            tail = lend;
        } else if(!ll && rr) {
            util(rr, rend);
            root->right = rr;

            tail = rend;
        } else {
            util(ll, lend);
            util(rr, rend);

            root->right = ll;
            lend->right = rr;

            tail = rend;
        }
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        TreeNode *tail = NULL;
        util(root, tail);
        tail->right = NULL;
        tail->left = NULL;
    }
};
*/
class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        TreeNode* left = root->left, *right = root->right;
        TreeNode* tail = root;
        if (left) {
            tail = helper(left);
            root->right = left;
            root->left = NULL;
        }
        if (right) {
            TreeNode* rtail = helper(right);
            tail->right = right;
            tail = rtail;
        }
        return tail;
    }

    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* tail = helper(root);
        tail->right = NULL;
    }
};


// 将右子树从根节点挪到左子树的最右边，然后将左子树作为根节点的右子树
// 更新root到root的右节点(也就是之前的左子树根节点)，重复以上动作
// 效果就是不断得将右子树挪到左子树，左子树又变成右子树
/*
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root) {
            if(root->left) {
                TreeNode* ptr = root->left;
                while(ptr->right) ptr = ptr->right;
                ptr->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right; //key
        }
    }
};
*/
