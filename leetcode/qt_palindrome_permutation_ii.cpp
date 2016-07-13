/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-13T02:13:34+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-13T02:25:42+08:00
*/



/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:
Given s = "aabb", return ["abba", "baab"].
Given s = "abc", return [].

Hint:
1. If a palindromic permutation exists, we just need to generate the first half of the string.
2. To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
*/

class Solution {
public:
    vector<string> helper(unordered_map<char, int>& count) {
        
    }
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        unordered_map<char, int> count;
        for(auto c:s) count[c]++;
        int odd = 0;
        for(auto i:count) if(i.second%2) odd++;
        if(odd>1) return ans; //不可能构成palindrome
        if(odd==0) {

        } else {

        }
    }
};
