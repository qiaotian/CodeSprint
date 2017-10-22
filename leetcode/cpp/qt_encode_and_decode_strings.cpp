/**
* @Author: Tian Qiao
* @Date:   2016-07-14T01:31:04+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-14T01:31:41+08:00
* @Inc: Google
* @Difficulty: Medium
*/

/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:
string encoded_string = encode(strs);
and Machine 2 does:
vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.
Implement the encode and decode methods.

Note:
1. The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
2. Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
3. Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/


// 输出过长
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(int i=0; i<strs.size(); i++) {
            string cur = strs[i];
            //空字符串处理
            if(cur=="") {
                ans+="bc";
                continue;
            }

            for(auto j:cur) ans = ans+j+j;// ans+=(j+j)会有问题
            ans+= i==strs.size()-1?"":"ab";
        }
        cout << ans << endl;
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        string cur;
        for(int i=0; i<s.size(); i=i+2) {
            if(s[i]==s[i+1]) cur+=s[i];
            else if(s[i]=='a' && s[i+1]=='b'){
                ans.push_back(cur); cur = "";
            } else {
                ans.push_back(""); cur = "";
            }
        }
        return ans;
    }
};

// https://discuss.leetcode.com/topic/22798/accepted-simple-c-solution
// 即使源字符串中包含<length> + '@' + str的形式也没有关系，因为改编码不关心字符串
// 内容，根据length截取子串，子串可以是任意格式
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string &str: strs) {
            int len = str.size();
            encoded += to_string(len) + "@" + str;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> r;
        int head = 0;
        while (head < s.size())    {
            int at_pos = s.find_first_of('@', head);
            int len = stoi(s.substr(head, at_pos - head));
            head = at_pos + 1;
            r.push_back(s.substr(head, len));
            head += len;
        }

        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
