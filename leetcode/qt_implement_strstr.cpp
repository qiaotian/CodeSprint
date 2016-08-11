/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()) return -1;
        for(int i=0; i<haystack.size()-needle.size()+1; i++){
            if(haystack.substr(i, needle.size())==needle) return i;
        }
        return -1;
    }
};
