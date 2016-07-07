/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-07T23:58:49+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-08T00:29:49+08:00
* @Inc: LinkedIn, Uber
*/

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples:
input: 1
output:
[]
input: 37
output:
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]


// beats 40%
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> factors;
    // pos 指向当前最小因素
    // 找到最小元素为factors[pos]的所有组合
    void helper(vector<int>& cur, int pos, int target) {
        if(target==1) {
            ans.push_back(cur);
            return;
        }
        for(int i=pos; i<factors.size(); i++) {
            if(target%factors[i]) continue; //不能整除
            cur.push_back(factors[i]);
            helper(cur, i, target/factors[i]);
            cur.pop_back();
        }
    }
    vector<vector<int>> getFactors(int n) {
        if(n<4) return ans;
        for(int i=2; i<=n/2; i++) {
            if(n%i==0) factors.push_back(i);
        }
        sort(factors.begin(), factors.end());

        vector<int> cur;
        helper(cur, 0, n);
        return ans;
    }
};

// beats 90%
class Solution {
public:
    void getResult(vector<vector<int>> &result,vector<int> &cur,int n){
        int i=cur.empty()?2:cur.back();
        for(;i<=n/i;++i){
            if(n%i==0){
                cur.push_back(i);
                cur.push_back(n/i);
                result.push_back(cur);
                cur.pop_back();
                getResult(result,cur,n/i);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> cur;
        getResult(result,cur,n);
        return result;
    }
};
