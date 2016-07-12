/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-13T01:32:55+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-13T02:12:04+08:00
* @Inc: Apple, Amazon, Uber
* @Difficulty: Medium
*/



/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/

/* Wrong
class Solution {
public:
    void reverseWords(string &s) {
        // delete redundent space
        int head = 0, tail = 0; // 头部空格数目
        while(s[0]==' ') s = s.substr(1, s.size()-1);
        while(s[s.size()-1]==' ') s = s.substr(s.size()-1);

        reverse(s.begin(), s.end());
        int start = 0;
        while(1) {
            int n = s.find(' ', start);
            if(n!=string::npos){
                reverse(s.begin()+start, s.begin()+n);
                start = n+1;
            } else {
                reverse(s.begin()+start, s.end());
                return;
            }
        }
    }
};
*/
class Solution {
public:

    // function to reverse any part of string from i to j
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        }
    }

    void reverseWords(string &s) {
        int i=0, j=0; // left and right index of substring
        int l=0;
        int len=s.length();
        int wordcount=0;

        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break; // all characters in string are spaces
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;}
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;

        }

        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }
};
