/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-01T19:32:33+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-01T20:35:18+08:00
* @License: Free License
* @Difficulty: Medium
*/

/**
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
*/



/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depth(vector<NestedInteger>& nestedList) {
        int maxdep = 1;
        for(auto i:nestedList) {
            if(!i.isInteger()) maxdep = max(maxdep, depth(i.getList())+1);
        }
        return maxdep;
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int sum = 0;
        int layer = depth(nestedList);
        for(auto i:nestedList) {
            if(i.isInteger()) {
                sum+=layer*i.getInteger();
            } else {
                sum+=depthSumInverse(i.getList());
            }
        }
        return sum;
    }
};

// 题目给出的test case:[[-1],[[-1]]], expected output is -3，而我给出的是-2，我认为两个
// -1都是叶子节点，而题目给的结果我认为有误。

// 网友给出的答案
// https://leetcode.com/discuss/110000/4ms-one-pass-dfs-c-solution
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> result;
        for(auto ni : nestedList) {
            dfs(ni, 0, result);
        }
        //post processing
        int sum = 0;
        for(int i = result.size()-1,level = 1; i >=0; i--, level++) {
            sum += result[i]*level;
        }

        return sum;
    }

private:
    void dfs(NestedInteger &ni, int depth, vector<int> & result) {
        if(result.size() < depth+1) result.resize(depth+1);
        if(ni.isInteger()) {
            result[depth] += ni.getInteger();
        } else {
            for(auto n_ni : ni.getList()) {
                dfs(n_ni, depth+1, result);
            }
        }
    }
};

// https://leetcode.com/discuss/110075/no-depth-variable-no-multiplication
class Solution {
public:
    int depthSumInverse(vector<NestedInteger> nestedList) {
        int unweighted = 0, weighted = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (NestedInteger ni : nestedList) {
                if (ni.isInteger())
                    unweighted += ni.getInteger();
                else
                    for(auto i:ni.getList())
                        nextLevel.push_back(i);
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;
    }
};
