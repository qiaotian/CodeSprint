/**
* @Author: Tian Qiao
* @Date:   2016-07-25T01:45:58+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-25T01:48:32+08:00
* @Inc: Facebook
* @Difficulty: Hard
*/

/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
click to show more hints.
Hints:
This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

// 注意：
// 1. 输入prerequisites可能含有相同元素，需要去重
// 2. dict和indegree在处理过程中不会改变容器大小，所以可以使用vector
// 3. courses在处理过程中需要动态改变大小，所以需要使用unordered_set，
//    注意该过程中只能使用while(判空)，切不可使用迭代器，为处理过程中
//    存在频繁增加和删除的操作。

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;

        vector<unordered_set<int>> dict(numCourses, unordered_set<int>()); // the successive courses of each course
        vector<int> indegree(numCourses, 0); // indegree of each course
        unordered_set<int> courses;
        for(int i=0; i<numCourses; i++) courses.insert(i);

        unordered_set<int> unduplicator; //去重
        for(auto p:prerequisites) unduplicator.insert(p.first*numCourses+p.second); //去重

        for(auto p:unduplicator) {
            int first = p/numCourses;
            int second = p%numCourses;
            dict[second].insert(first);
            indegree[first]++;
            courses.erase(first);
        }

        while(!courses.empty()) {
            int tmp = *courses.begin();
            courses.erase(tmp);
            ans.push_back(tmp);

            for(auto i:dict[tmp]) {
                indegree[i]--;
                if(indegree[i]==0) courses.insert(i);
            }
        }
        if(ans.size()!=numCourses) ans.clear();
        return ans;
    }
};
