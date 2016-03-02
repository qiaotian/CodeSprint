/*
class Solution {
private:
    vector<int> res;
    void util(vector<int>& nums, vector<char>& opts) {
        if(opts.size() == 0) res.push_back(nums[0]);
        for(int i = 0; i < opts.size(); i++) {
            
        }
    }
public:
    vector<int> diffWaysToCompute(string input) {
        
        vector<int> nums;
        vector<char> opts;
        int number = 0;
        for(int i = 0; i < input.size()); i++) {
            if(isdigit(input[i])) {
                number = 10 * number + input[i] - '0';
            } else {
                nums.push_back(number);
                opts.push_back(input[i]);
            }
        }
        // todo
        
        return res;
    }
};*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        for (int i=0; i<input.size(); i++) {
            char c = input[i];
            if (ispunct(c))
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                        output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
        }
        return output.size() ? output : vector<int>{stoi(input)};
    }
};

/**
 * Tip
 * 返回结果允许重复，无需考虑去重
 * 1. 如果使用vector存储数字和云算法，如何解决更新vector容量的问题（使用erase消耗较大）
 * 2. 直接处理string可以直接替换字符串，不过需要反复判定是否是数字
 * 
 * Reference
 * 1. https://leetcode.com/discuss/48468/1-11-lines-python-9-lines-c
 * /
