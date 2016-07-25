// Time Complexity: O(n)
// Space Complexity: O(n)

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// DFS
/* 注意该写法的错误之处#1和#2
class Solution {
public:
    unordered_set<UndirectedGraphNode*> s; #1
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        // 如果节点已经生成，直接返回该节点的指针即可
        auto search = s.find(node); //#2 这里不能如此使用，因为这里查找需要根据label查找，而非地址
        if(search!=s.end()) return *search;

        UndirectedGraphNode *curr = new UndirectedGraphNode(node->label);
        s.insert(curr);
        vector<UndirectedGraphNode*> ngbs = node->neighbors;
        for(auto i:ngbs) {
            if(i->label==curr->label) {
                cout << "self" << endl;
                //自己指向自己
                curr->neighbors.push_back(curr);
            } else {
                cout << "Others" << endl;
                UndirectedGraphNode* tmp = cloneGraph(i);
                curr->neighbors.push_back(tmp);
            }
        }
        return curr;
    }
};
*/
// DFS
// 修改
class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> s; // #1 map label to node pointer
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        // 如果节点已经生成，直接返回该节点的指针即可
        auto search = s.find(node->label); //#2
        if(search!=s.end()) return search->second;

        UndirectedGraphNode *curr = new UndirectedGraphNode(node->label);
        s.insert({node->label, curr});
        vector<UndirectedGraphNode*> ngbs = node->neighbors;
        for(auto i:ngbs) {
            if(i->label==curr->label) {
                //自己指向自己
                curr->neighbors.push_back(curr);
            } else {
                UndirectedGraphNode* tmp = cloneGraph(i);
                curr->neighbors.push_back(tmp);
            }
        }
        return curr;
    }
};

// BFS
class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if(!node) return NULL;

            // map the origin to its copy
            unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
            copied[node] = new UndirectedGraphNode(node->label);
            queue<const UndirectedGraphNode *> que;
            que.push(node);
            while(!que.empty()) {
                auto node = que.front();
                que.pop();

                for(auto n : node->neighbors) {
                    if(copied.find(n) == copied.end()) {
                        copied[n] = new UndirectedGraphNode(n->label);
                        que.push(n);
                    }

                    copied[node]->neighbors.push_back(copied[n]);
                }
            }
            return copied[node];
        }
};
