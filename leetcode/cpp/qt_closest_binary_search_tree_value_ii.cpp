/**
* @Author: Tian Qiao
* @Date:   2016-08-03T19:44:10+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-03T19:47:30+08:00
* @Inc: Google
* @Difficulty: Hard
*/



/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hint:

Consider implement these two helper functions:
getPredecessor(N), which returns the next smaller node to N.
getSuccessor(N), which returns the next larger node to N.
Try to assume that each node has a parent pointer, it makes the problem much easier.
Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
You would need two stacks to track the path in finding predecessor and successor node separately.
*/

// O(N*logK)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Dict {
    TreeNode *node;
    double delta;
    Dict(TreeNode* node, double target):node(node), delta(abs(node->val-target)) {}
};

struct cmp{
    bool operator() ( Dict a, Dict b ){
        return a.delta < b.delta;
    }
};

class Solution {
private:
    //auto cmp = [](Dict left, Dict right) { return (left.delta) < (right.delta);};
    //priority_queue<Dict, vector<Dict>, decltype(cmp)> pq(cmp);
    priority_queue<Dict, vector<Dict>, cmp> pq;

    void preorder(TreeNode* root, double target, int k) {
        if(!root) return;
        preorder(root->left, target, k);
        double tmp = abs(root->val-target);
        if(pq.size() < k) pq.push(Dict(root, target));
        else {
            if(tmp < pq.top().delta) {
                pq.pop();
                pq.push(Dict(root, target));
            }
        }
        preorder(root->right, target, k);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        preorder(root, target, k);
        //for(auto dict:pq) {
        //    ans.push_back(dict.node->val);
        //}
        while(!pq.empty()) {
            ans.push_back(pq.top().node->val);
            pq.pop();
        }
        return ans;
    }
};


// O(LogN)
// 使用双栈
class Solution {
public:
    int get_next_pred(stack<TreeNode*>& pred){
        int res = pred.top()->val;
        TreeNode* x = pred.top()->left;
        pred.pop();
        while(x){
            pred.push(x);
            x = x->right;
        }
        return res;
    }

    int get_next_succ(stack<TreeNode*>& succ){
        int res = succ.top()->val;
        TreeNode* x = succ.top()->right;
        succ.pop();
        while(x){
            succ.push(x);
            x = x->left;
        }
        return res;
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        TreeNode* curr = root;
        stack<TreeNode*> pred;
        while(curr){
            if(curr->val == target){
                pred.push(curr);
                break;
            }
            else if(curr->val < target){
                pred.push(curr);
                if(!curr->right) break;
                curr = curr->right;
            }
            else{
                if(!curr->left) break;
                curr = curr->left;
            }
        }
        stack<TreeNode*> succ;
        curr = root;
        while(curr){
            if(curr->val == target){
                succ.push(curr);
                break;
            }
            else if(curr->val>target){
                succ.push(curr);
                if(!curr->left) break;
                curr = curr->left;
            }
            else{
                if(!curr->right) break;
                curr = curr->right;
            }
        }
        int found = 0;
        if(!succ.empty() && !pred.empty() && succ.top()->val == pred.top()->val) get_next_pred(pred);
        while(found<k){
            if(succ.empty()) res.push_back(get_next_pred(pred));
            else if(pred.empty()) res.push_back(get_next_succ(succ));
            else{
                double succ_diff = abs((double)succ.top()->val - target);
                double pred_diff = abs((double)pred.top()->val - target);
                if(succ_diff>pred_diff) res.push_back(get_next_pred(pred));
                else res.push_back(get_next_succ(succ));
            }
            found++;
        }
        return res;
    }
};
