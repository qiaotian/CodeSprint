/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        int start = 0; int end = s.size()-1;
        while(start < end) {
            swap(s[start++], s[end--]);
        }
        return s;
    }
};
