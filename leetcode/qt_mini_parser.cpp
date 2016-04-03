/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
*/



/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


/***** Wrong Solution
class NestedInteger {
private:
    vector<int> nums;
    vector<NestedInteger> nestints;
}

class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ans;
        if(s[0]!='[') {
            if(s.size()>2) ans.nums.push_back(stoi(s.substr(1, s.size()-2))); 
            return ans;
        }

        string str = s.substr(1, s.size()-2);
    
        int pre = 0;
        int cur = 0;

        for(int i=0; i<str.size(); i++) {
            if(str[pre]=='[')
        }

        return ans;
    }
};
*/

// https://discuss.leetcode.com/topic/54258/python-c-solutions
class Solution {
public:
    NestedInteger deserialize(string s) {
        istringstream in(s);
        return deserialize(in);
    }
private:
    NestedInteger deserialize(istringstream &in) {
        int number;
		// 如果第一个字符是'['，那么 in>>number 执行失败, failbit被设置
        if (in >> number) return NestedInteger(number);
		// 取消failbit标志位设置（clear() is used to unset the failbit after unexpected input）
        in.clear();
		// get() is used to extract the first character
        in.get();
        NestedInteger list;
		// peek() is used to read the first character without extraction, different with get()
        while (in.peek() != ']') {
            list.add(deserialize(in));
            if (in.peek() == ',') in.get();
        }
		// skip the ']'
        in.get();
        return list;
    }
};

