/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-10T11:55:52+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-10T12:45:55+08:00
*/



/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
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
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

// 不可以使用DFS, 否则针对[3,9,8,4,0,1,7,null,null,null,2,5]中的8和2次序会翻转
 class Solution {
 public:
     vector<vector<int>> ans;
     unordered_map<int, vector<int>> layer2nodes;
     //unordered_map<TreeNode*, int> node2layer;

     vector<vector<int>> verticalOrder(TreeNode* root) {
         if(!root) return ans;

         //if(dict.find(layer)==dict.end()) dict.insert({layer, vector<int>(1, root->val)});
         //else dict[layer].push_back(root->val);
         //dict[layer].push_back(root->val);

         queue<pair<TreeNode*, int>> que; // node 2 layer
         que.push({root, 0});
         while(!que.empty()) {
             int n = que.size();
             for(int i=0; i<n; i++) {
                 TreeNode* node = que.front().first;
                 int layer = que.front().second;
                 que.pop();

                 layer2nodes[layer].push_back(node->val);

                 if(node->left) que.push({node->left, layer-1});
                 if(node->right) que.push({node->right, layer+1});
             }
         }

         map<int, vector<int>> tmp;
         for(auto i:layer2nodes) tmp.insert({i.first, i.second});
         for(auto i:tmp) ans.push_back(i.second);

         return ans;
     }
 };
