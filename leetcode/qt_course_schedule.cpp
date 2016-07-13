/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-13T10:14:33+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-13T11:25:37+08:00
* @Inc: Apple, Yelp
* @Difficulty: Medium
*/



/**
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


Hints:
1. This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
2. Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
3. Topological sort could also be done via BFS.
*/

// My Solution
class Solution {
public:
    bool findCircle(int start ,unordered_map<int, vector<int>>& dependencies, vector<bool>& nonCycl, vector<bool>& visited) {
        if(visited[start]) return true; //访问过start
        if(nonCycl[start]) return false; //先前访问过且无环，则直接返回；否则TLE

        visited[start] = true;
        vector<int> next = dependencies[start];
        for(auto j:next) {
            if(nonCycl[j]) continue; //j点不存在环，直接跳过
            if(findCircle(j, dependencies, nonCycl, visited)) return true;
        }
        nonCycl[start] = true;
        visited[start] = false;

        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 1) return true;
        unordered_map<int, vector<int>> dependencies;
        for(auto i:prerequisites) dependencies[i.first].push_back(i.second);

        vector<bool> visited(numCourses, false);
        vector<bool> nonCycl(numCourses, false); //不存在环的点
        for(int i=0; i<numCourses; i++) {
            if(findCircle(i, dependencies, nonCycl, visited)) return false;//存在环，不能完成课程
        }
        return true;
    }
};


// https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions/2
// DFS(需要定义两个标记量，visisted和onpath)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true;
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        return onpath[node] = false;
    }
};

// BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++)
                if (!degrees[j]) break;
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j])
                degrees[neigh]--;
        }
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};
