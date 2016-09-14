/*
Given an integer n, return [1, n] in lexicographical order.
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000. 
*/

// TLE
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> strs;
        for(int i=1; i<n+1; i++) {
            string tmp = to_string(i);
            strs.push_back(tmp);
        }
        sort(strs.begin(), strs.end());
        for(auto s:strs) {
            int tmp = stoi(s);
            ans.push_back(tmp);
        }
        return ans;
    }
};


// DFS
// 1->10->100->1000->...->10001->10002->...2->20->...
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<10; i++)
            util(ans, i, n); //收集以1,2,3...,i,...9开头的数字
        return ans;
    }
    void util(vector<int>& ans, int cur, int& bound) {
        if(cur > bound) return;
        ans.push_back(cur);
        for(int i=0; i<10; i++) {
            util(ans, cur*10+i, bound);
        }
    }
};


// Faster Method with no recursion
// https://discuss.leetcode.com/topic/55131/ac-240ms-c-solution
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) 
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0)
                    cur /= 10;
            }
        }
        return res;
    }
};
