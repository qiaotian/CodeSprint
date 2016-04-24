/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * 满树的节点数容易计算，因此关键在于找到最后一个节点什么位置
 * 分别计算左子树和右子树高度；
 * 然后比较两颗子树的高度
 * 1. 如果左高于右，那么说明最后一个节点在左子树上，那么右子树为满树，易知右子树的节点数；
 * 2. 若果左等于右，那么说明最后一个几点在右子树上，那个左子树为满树，易知左子树的节点数；
 * 然后递归方式求解位置的左（右）子树节点数
 *
 * Time: 140ms, beats: 72%
 */

/*
class Solution {
public:
    int calHeight(TreeNode *root) {
        int ans  = 0;
        if(!root) return ans;
        ans++;
        TreeNode* tmp = root;
        while(tmp->left) {
            tmp = tmp->left;
            ans++;
        }
        return ans;
    }

    int helper(TreeNode* root) {
        int sum = 0;
        if(!root) return sum;
        sum++;
        int ll = calHeight(root->left); // 左子树高度
        int rr = calHeight(root->right); // 右子树高度
        if(ll > rr) {
            sum += (1<<rr)-1; //替换pow(1, rr)-1
            sum += helper(root->left);
        } else {
            sum += (1<<ll)-1; //替换pow(1, ll)-1
            sum += helper(root->right);
        }
        return sum;
    }

    int countNodes(TreeNode* root) {
        return helper(root);
    }
};
*/

/**
 * 判定是否为满树
 * 如果是满树，直接返回结果，否则判定左右子树是否为满树
 *
 * Time:220, beats:37%
 */
/*
class Solution {
public:

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hl=0, hr=0;

        TreeNode *l=root, *r=root;
        while(l) {hl++;l=l->left;}
        while(r) {hr++;r=r->right;}
        if(hl==hr) return (1<<hl)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
*/

/**
 * 将所有节点分为两部分：1. 1~height-1层满树 和 2.最后一层
 * 第一部分比较好计算，第二部分需要递归求解
 *
 * Time: 72ms, beats: 98%
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *temp = root;
        int height = 0, count = 0, level;
        // 计算整棵树的高度
        while(temp) {
            temp = temp->left;
            height ++;
        }

        temp = root;
        level = height - 2;
        while(level >= 0) {
            TreeNode *left = temp->left;
            for(int i = 0;i < level;i ++) {
                left = left->right;
            }
            if(left) {
                temp = temp->right;
                count += (1 << level);
            } else temp = temp->left;
            level --;
        }
        if(temp) count ++;
        return (1 << (height - 1)) + count - 1;
    }
};
