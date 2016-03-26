/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// (52ms, beat 24%, bad)
/*
class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, \
                     int instart, int inend, int poststart, int postend) {
        if(instart > inend || poststart > postend) return NULL;

        TreeNode* root = new TreeNode(postorder[postend]);

        if(instart == inend || poststart == postend) return root;

        int rootindex = 0;
        for(int i = instart; i <= inend; i++) {
            if(inorder[i] == postorder[postend]) {
                rootindex = i;
                break;
            }
        }
        root->left = rootindex==instart ? NULL:helper(inorder, postorder,\
                                              instart, rootindex-1,\
                                              poststart, poststart+rootindex-1-instart);
        root->right = rootindex==inend ? NULL:helper(inorder, postorder,\
                                                     rootindex+1, inend,\
                                                     postend-inend+rootindex, postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inlen = inorder.size();
        int postlen = postorder.size();
        return helper(inorder, postorder, 0, inlen-1, 0, postlen-1);
    }
};
*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;

        root = new TreeNode(postorder.back());
        stn.push(root);
        postorder.pop_back();

        while(true)
        {
            if(inorder.back() == stn.top()->val) {
                p = stn.top();
                stn.pop();
                inorder.pop_back();
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val) continue;
                p->left = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.push(p->left);
            } else {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p;
                stn.push(p);
            }
        }
        return root;
    }
};
