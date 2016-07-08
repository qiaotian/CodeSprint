/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-03T14:19:12+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-03T14:24:48+08:00
* @Inc: LinkedIn
* @Difficulty: Easy
*/

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

________________________________________________________________________________

// words中的单词会有重复
// word1和word2不会相同
class Solution {
public:
    // 适用于多次查询，每次查询的平均时间复杂度为O(1)
    /* 解法错误，如果words中有重复单次，那么更新index会需要更为复杂的规则
    int shortestDistance(vector<string>& words, string word1, string word2) {
        if(word1==word2) return 0;
        unordered_map<string, int> dict;
        for(int i=0; i<words.size(); i++) {
            // dict.insert({words[i], i}); //该写法也可以
            dict.insert(make_pair(words[i], i));
        }
        return abs(dict[word1]-dict[word2]);
    }*/

    // 适用于单次查询，每次查询时间复杂度O(N)
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int dist = INT32_MAX;
        int pre = -1;
        for(int i=0; i<words.size(); i++) {
            if(words[i]==word1 || words[i]==word2) {
                if(pre==-1 || words[i]==words[pre]) pre = i;
                else dist = min(dist, i-pre);
                pre = i;
            }
        }
        return dist;
    }
};
