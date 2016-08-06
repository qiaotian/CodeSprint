/**
* @Author: Tian Qiao
* @Date:   2016-07-10T19:18:26+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-05T06:15:53+08:00
* @Inc: Microsoft
* @Difficulty: Hard
* @Tag: Tree, DFS
*/



/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/


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
