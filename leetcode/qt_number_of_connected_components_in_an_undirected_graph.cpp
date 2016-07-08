/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-08T15:32:58+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-08T23:58:00+08:00
*/


Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


// BFS beats 1%, worst
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        //vector<int> hashmap(n, INT32_MAX); //map the number to its connected minimal number
        int ans = 0;
        vector<bool> visited(n, false);

        queue<int> que;
        for(int m=0; m<n; m++) {
            if(visited[m]) continue;
            que.push(m); //从0开始BFS
            visited[m] = true;
            while(!que.empty()) {
                int que_size = que.size();
                for(int i=0; i<que_size; i++) {
                    int tar = que.front();
                    que.pop();
                    for(auto j:edges) {
                        if(j.first==tar && !visited[j.second]) {
                            que.push(j.second);
                            visited[j.second]=true;
                            continue;
                        }
                        if(j.second==tar && !visited[j.first]) {
                            que.push(j.first);
                            visited[j.first]=true;
                            continue;
                        }
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};

//
// 并查集union-find algorithm
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> p(n);
        iota(begin(p), end(p), 0);
        for (auto& edge : edges) {
            int v = edge.first, w = edge.second;
            // find the group that v belongs to and assign the root to v
            // find the group of w and belongs to the root to w
            // use v=p[v] instead of p[v]=p[p[v]] is to use path compression,
            // which could make it faster
            while (p[v] != v) v = p[v] = p[p[v]];
            while (p[w] != w) w = p[w] = p[p[w]];
            p[v] = w;
            // v == w means origin v and w are in the same group
            // and vice versa, therefore merge v and w into the same
            // group should decrease the total number of groups
            n -= v != w;
        }
        return n;
    }
};
