/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        int right = s.size()-1;
        
        // point right to the first nonspace character from right side
        while(s[right]==' ') right--;
        int left = right;
        
        // point left to the pre character of last word
        while(left>=0 && s[left]!=' ') left--;
        
        return right-left;
    }
};
