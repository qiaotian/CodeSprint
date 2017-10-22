/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-10T19:18:26+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-13T01:33:56+08:00
*/

/*
Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> vec;
        string str;
        for(int i = 0; i<s.size(); i++) {
            //if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) {
            if(s[i]!=' ') {
                str+=s[i];
                continue;
            }
            if(s[i]==' ' && !str.empty()) {
                vec.push_back(str);
                str = "";
                continue;
            }
        }

        if(!str.empty()) vec.push_back(str);

        s = "";
        for(int i=vec.size()-1; i>=0; i--) {
            s+= vec[i];
            if(i!=0) s+=' ';
        }
    }
};
