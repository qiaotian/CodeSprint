// 1st solution (1136ms, beats 65%)
/*
class Solution {
public:
    struct Node {
        unordered_set<int> neighbours;
        bool isLeaf() const{return neighbours.size() == 1;}
    };
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if(n == 1) {
            res.push_back(0);
            return res;
        }
        if(n == 2) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        
        // construct the graph
        vector<Node> graph(n);
        for(auto i : edges) {
            //graph[get<0>(i)].insert(get<1>(i));
            //graph[get<1>(i)].insert(get<0>(i));
            graph[i.first].neighbours.insert(i.second);
            graph[i.second].neighbours.insert(i.first);
        }
        
        // find all leaves
        vector<int> leaves1;
        vector<int> leaves2;
        vector<int>* ptr1 = & leaves1; 
        vector<int>* ptr2 = & leaves2;
        for(int i = 0; i < graph.size(); i++) {
            if(graph[i].isLeaf()) ptr1->push_back(i);
        }
        
        // delete leaves layer by layer
        while(1) {
            for(auto i : *ptr1) {
                for(auto j : graph[i].neighbours) {
                    graph[j].neighbours.erase(i);
                    if(graph[j].isLeaf()) ptr2->push_back(j);
                }
            }
            if(ptr2->empty()) return *ptr1;
            ptr1->clear();
            swap(ptr1, ptr2);
        }
    }
};
*/

// 2nd solution (1224ms, beats 25%)
class Solution {
public: 
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for(auto e: edges){
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        vector<int> degree(n, 0);
        for(int i=0; i<n; i++) degree[i]=graph[i].size();
        for(int i=0, j, remain=n; i<n && remain>2; i++){
            vector<int> del; // nodes to delete
            for(j=0; j<n; j++){
                if(degree[j]==1) {
                    remain--;
                    del.push_back(j);
                    degree[j]=-1;
                }
            }
            for(auto k: del){ //delete this node and all connected edges 
                for(auto neigh: graph[k]) degree[neigh]--;
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if(degree[i]>=0) res.push_back(i);
        }
        return res;
    }
};
/**
 * The basic idea is "keep deleting leaves layer-by-layer, until reach the root."
 * Specifically, first find all the leaves, then remove them. After removing, some nodes will become new leaves. So we can continue remove them. Eventually, there is only 1 or 2 nodes left. If there is only one node left, it is the root. If there are 2 nodes, either of them could be a possible root.
 * Time Complexity: Since each node will be removed at most once, the complexity is O(n).
 * 
 * Thanks for pointing out any mistakes.
 * Updates: More precisely, if the number of nodes is V, and the number of edges is E. The space complexity is O(V+2E), for storing the whole tree. The time complexity is O(E), because we gradually remove all the neighboring information. As some friends pointing out, for a tree, if V=n, then E=n-1. Thus both time complexity and space complexity become O(n).
 * 
 * /

