/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T18:37:08+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-09T20:25:10+08:00
* @Inc: Zenefits
* @Difficulty: Medium
*/


/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/

/* TLE(单调递增或递减的情况)
class Solution {
public:
    bool util(vector<int>&preorder, int start, int end) {
        // 空序列
        if(start>end) return true;
        // 左右子树都不存在
        if(end==start) return true;
        // 左右子树只有一个存在且树的长度为1
        if(end-start==1) return true;

        int lstart = start+1, lend = INT32_MIN;
        int rstart = INT32_MAX, rend = preorder.size()-1;
        for(int i = lstart; i<preorder.size(); i++) {
            if(preorder[i]<preorder[0]) lend = i;
        }
        for(int i = rend; i>=start+1; i--) {
            if(preorder[i]>preorder[0]) rstart = i;
        }

        // 异常检测
        if((lstart<lend && rstart!=start+1) ||\
           (rstart<rend && lend!=end) ||\
           (lstart<=lend && rstart<rend && lend+1!=rstart)) {
            return false;
        }

        bool l = util(preorder, lstart, lend);
        bool r = util(preorder, rstart, rend);
        return l&&r;
    }

    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size()<3) return true; //两个数字无法判定是否是BST
        return util(preorder, 0, preorder.size()-1);
    }
};
*/

/*判定是否是先序和还原先序树的复杂是不一样的，应该一种思路思考，调高效率*/

/*
Kinda simulate the traversal, keeping a stack of nodes (just their values) of which we're still in the left subtree. If the next number is smaller than the last stack value, then we're still in the left subtree of all stack nodes, so just push the new one onto the stack. But before that, pop all smaller ancestor values, as we must now be in their right subtrees (or even further, in the right subtree of an ancestor). Also, use the popped values as a lower bound, since being in their right subtree means we must never come across a smaller number anymore.
*/
class Solution{
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT32_MIN;
        vector<int> path;
        for (int p : preorder) {
            if (p < low) return false;
            while (!path.empty() && p > path.back()) {
                low = path.back();
                path.pop_back();
            }
            path.push_back(p);
        }
        return true;
    }
};

// 从preorder开始讲降序数列入栈，也就是将树的最左侧的节点依次入栈
// 如果遇到某个数字不满足降序，那么它一定是栈中某个节点的右子树根节点
// 因此可以将该节点对应左子树全部出栈。
// 简而言之，降序说明访问的是左子树，升序说明访问的是右子树

// https://discuss.leetcode.com/topic/21217/java-o-n-and-o-1-extra-space
