/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T11:51:45+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-09T15:13:43+08:00
* @Inc: Google
*/

/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    /
   2
  /
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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

 /*
class Solution {
public:
   int longestConsecutive(TreeNode* root) {
       if(!root) return 0;
       if(!root->left && !root->right) return 1; //此时返回值应与parent有关，不能直接返回1

       int ans = 0;
       if(root->left) {
           if(root->left->val==root->val+1)
               ans = max(ans, 1+longestConsecutive(root->left));
           else
               ans = max(ans, longestConsecutive(root->left));
       }
       if(root->right) {
           if(root->right->val==root->val+1)
               ans = max(ans, 1+longestConsecutive(root->right));
           else
               ans = max(ans, longestConsecutive(root->right));
       }
       return ans;
   }
};
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        sort(nums.begin(), nums.end());

        // dp[i]: 截止到第i个元素，最大子集长度和当前节点在最大子集中的上一节点
        vector<pair<int, int>> dp(nums.size(), make_pair(1, -1));
        // len:最大整除子集长度
        // tail:及最大整除子集的末尾元素索引
        int len = 1, tail = 0;

        for (int i = 1; i < nums.size(); i++) {
            int largest = 1, parentIdx = -1;
            // 针对nums[i]，遍历nums[i]之前的因子，找到
            // 以nums[i]结尾的最大整除子集长度 largest
            // 和父节点parent
            for (int j = i - 1; j > - 1; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j].first + 1 > largest) {
                        parentIdx = j;
                        largest = dp[j].first + 1;
                    }
                }
            }
            dp[i].first = largest;
            dp[i].second = parentIdx;

            if (largest > globalLargest) {
                tail = i;
                len = largest;
            }
        }
        vector<int> ret;
        for (int idx = globalLargestIdx; idx != -1; idx = dp[idx].second) {
            //ret.push_back(nums[idx]);
            ret.insert(ret.begin(), nums[idx]);
        }
        return ret;
    }
};
