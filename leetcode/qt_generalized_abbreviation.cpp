/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T09:47:09+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T10:40:30+08:00
* @Inc: Google
*/



———————————————————————————————————————————————————————————————————————————————
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
———————————————————————————————————————————————————————————————————————————————
// Bit Manipulation
// my solution beats 17%, bad
class Solution {
public:
    string transform(string& str, int mask) {
        // "word"与2(0010)作用得到wo1d
        int len = str.size();
        //vector<int> cache(len, 0);
        int cache[len];
        for(int i=0; i<len; i++) {
            cache[len-1-i] = mask & 1;
            mask>>=1;
        }
        string ans;
        int count = 0; // 连续1的个数
        for(int i=0; i<len; i++) {
            if(cache[i]==0) {
                ans+=(count==0?"":to_string(count));
                ans+=str[i];
                count = 0;
            } else { //cache[i]==1
                count++;
            }
        }
        ans+=(count==0?"":to_string(count));
        return ans;
    }
    vector<string> generateAbbreviations(string word) {
        int n = pow(2, word.size());
        vector<string> ans;
        for(int i=0; i<n; i++) {
            ans.push_back(transform(word, i));
        }
        return ans;
    }
};
// 对于长度为N(4)的单词
// 列举
// 0000, 0001, 0010, 0011, 0100, 0101..., 1100, 1101, 1110, 1111
// 合并相邻1
// 0000, 0001, 0010, 002 , 0100, 0101...,  200,  201,   30, 4
// 单词中对应于0的位子的字母被保留，其余替换成相应的数字即可
// O(N*2^N)

// Backtracking
// beats 76%, good
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        generateAbbreviationsHelper(word, "", 0, result, false);
        return result;
    }

    void generateAbbreviationsHelper(string& word, string abbr, int i, vector<string>& result, bool prevNum) {
        if (i == word.length()) {
            result.push_back(abbr);
            return;
        }

        //第i个位置为字母的所有组合
        generateAbbreviationsHelper(word, abbr+word[i], i+1, result, false);
        //第i个数字为缩写的所有组合
        if (!prevNum) {
            // Add number abbreviations only when we added a character instead of an abbreviation earlier
            for (int len = 1; i+len <= word.length(); ++len) {
                generateAbbreviationsHelper(word, abbr+to_string(len), i+len, result, true);
            }
        }
    }
};
