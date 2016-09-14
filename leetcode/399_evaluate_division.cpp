/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/


// Hash + DFS
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values,
                                vector<pair<string, string>> queries) {
        vector<double> ans;
        unordered_map<string, unordered_map<string, double>> mmap;

        for(int i=0; i<equations.size(); i++) {
            mmap[equations[i].first].insert(make_pair(equations[i].second, values[i]));
            if(values[i]) mmap[equations[i].second].insert(make_pair(equations[i].first, 1.0/values[i]));
        }
        for(auto q:queries) {
            unordered_set<string> s; // used for storing the visited node
            double tmp = util(mmap, s, q);
            if(tmp) ans.push_back(tmp);
            else ans.push_back(-1.0);
        }
        return ans;
    }
    double util(unordered_map<string,unordered_map<string, double>> &m,
                unordered_set<string> &s,
                pair<string, string> q)
    {
        if(m[q.first].find(q.second) != m[q.first].end()) return m[q.first][q.second];
        for (auto i : m[q.first])
        {
            if(s.find(i.first) == s.end())
            {
                s.insert(i.first);
                double tmp = util(m, s, make_pair(i.first, q.second));
                if(tmp) return i.second*tmp;
            }
        }
        return 0;
    }
};
