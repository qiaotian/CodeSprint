/**
* @Author: Tian Qiao
* @Date:   2016-08-05T06:14:47+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-05T06:17:25+08:00
* @Inc: Microsoft, Bloomberg, Facebook
* @Difficulty: Hard
* @Tag: Tree, DFS ?
*/

/*
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?

Note:
You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// 1. BFS
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> que;
        que.push(root);
        while(!que.empty()) {
            int n = que.size();
            for(int i=0; i<n; i++) {
                TreeLinkNode* cur = que.front();
                que.pop();
                if(i!=n-1) cur->next = que.front();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
    }
};

// 2. Constant Extra Space
class Solution{
public:
    void connect(TreeLinkNode root) {
        TreeLinkNode* dummyHead = new TreeLinkNode(0);
        TreeLinkNode* pre = dummyHead;
        while (root != NULL) {
            if (root.left != NULL) {
                pre->next = root->left;
                pre = pre->next;
            }
            if (root->right != NULL) {
                pre->next = root->right;
                pre = pre->next;
            }
            root = root->next;
            if (root == NULL) {
                pre = dummyHead;
                root = dummyHead->next;
                dummyHead->next = NULL;
            }
        }
    }
}
