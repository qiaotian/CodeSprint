/**
* @Author: Tian Qiao
* @Date:   2016-07-27T23:08:16+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-27T23:08:18+08:00
* @Difficulty: Easy
* @Inc: Dropbox, Uber
* @Tag: Hash Table
*/

/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> pattern2index;
        map<string, int> word2index;
        istringstream stream(str);
        int i = 0;
        int n = pattern.size();
        for(string word; stream >> word; ++i){
            // i==n是为了检测str中的单词个数是否超过pattern的字符长度
            if(i==n || pattern2index[pattern[i]] != word2index[word]) return false;
            pattern2index[pattern[i]] = word2index[word] = i+1; // to avoid the otherwise double meaning of 0
        }
        return i==n;
    }
};

/****
 * Really nice i + 1:
 * I guess you do this because you want to avoid 0 appearing as values
 * since map will assign default 0 values once we index some non-existed keys
 * /
