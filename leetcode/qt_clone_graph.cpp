/**
* @Author: Tian Qiao
* @Date:   2016-07-13T23:19:02+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-13T23:19:11+08:00
*/



/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.
The graph has a total of three nodes, and therefore contains three parts as separated by #.
First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_set<UndirectedGraphNode*> s;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        // 如果节点已经生成，直接返回该节点的指针即可
        auto search = s.find(node);
        if(search!=s.end()) return *search;

        UndirectedGraphNode *curr = UndirectedGraphNode(node->label);
        s.insert(curr);
        vector<UndirectedGraphNode*> ngbs = node->neighbors;
        for(auto i:ngbs) {
            if(i==curr) {
                //自己指向自己
                curr.neighbors.push_back(cur);
            } else {
                UndirectedGraphNode* tmp = cloneGraph(i);
                curr.neighbors.push_back(tmp);
            }
        }
        return curr;
    }
};
