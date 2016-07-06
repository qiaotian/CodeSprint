/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T10:41:20+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T21:15:39+08:00
* @Inc: LinkedIn, Microsoft
* @Difficulty: Medium
*/

_______________________________________________________________________________

Given a collection of numbers that might contain "duplicates", return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
_______________________________________________________________________________


class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, unordered_map<int, int>& dict, int pos) {
        if(pos == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(auto& i:dict) {
            // 如果要改动dict的值，需要使用引用，否则修改无效
            if(i.second==0) continue; // skip if count is 0
            nums[pos] = i.first;
            i.second--;
            dfs(nums, dict, pos+1);
            i.second++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> dict; /// map number to its count
        for(auto i:nums) dict[i]++;
        dfs(nums, dict, 0);
        return res;
    }
};

// 错误优化方法
// #1处仍在遍历dict, #2确有可能删除元素, 虽然#3处做了恢复处理, 但是遍历dict已经被破坏, 会出错误
//
/*
class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, unordered_map<int, int>& dict, int pos) {
        if(pos == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(auto& i:dict) { // #1
            int key = i.first;
            int count = i.second;

            nums[pos] = key;
            if(count==1) dict.erase(key); // #2
            else dict[key]--;

            dfs(nums, dict, pos+1);
            dict[key] = count; //#3
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> dict; /// map number to its count
        for(auto i:nums) dict[i]++;
        dfs(nums, dict, 0);
        return res;
    }
};*/
