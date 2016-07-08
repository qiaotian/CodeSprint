/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-08T13:24:26+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-08T13:50:50+08:00
*/



This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
word1 and word2 may be the same and they represent two individual words in the list.
For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

// beat 7% bad
class Solution {
public:
    unordered_map<stirng, vector<int>> dict;
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        for(int i=0; i<words.size(); i++) {
            dict[words[i]].push_back(i);
        }

        int dist = INT32_MAX;
        if(word1==word2) {
            vector<int>& pos = dict[word1];
            for(int i=0; i<pos.size()-1; i++) {
                dist = min(dist, pos[i+1]-pos[i]);
            }
        } else {
            vector<int>& pos1 = dict[word1];
            vector<int>& pos2 = dict[word2];

            int idx1 = 0, idx2 = 0;
            while(idx1<pos1.size() && idx2<pos2.size()) {
                dist = min(dist, abs(pos1[idx1]-pos2[idx2]));
                if(idx1==pos1.size()-1 && pos1[idx1]<=pos2[idx2]) break;
                if(idx2==pos2.size()-1 && pos2[idx2]<=pos1[idx1]) break;

                if(pos1[idx1]<pos2[idx2]) idx1++;
                else idx2++;
            }
        }
        return dist;
    }
};

// beats 100%
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long dist = INT_MAX, i1 = dist, i2 = -dist;
        for (int i=0; i<words.size(); i++) {
            if (words[i] == word1)
                i1 = i;
            if (words[i] == word2) {
                if (word1 == word2)
                    i1 = i2;
                i2 = i;
            }
            dist = min(dist, abs(i1 - i2));
        }
        return dist;
    }
};

// 该题与shortest_word_distance_ii的不同之处在于允许word1和word2的去重问题，这样就不需要
// 使用hash。如果将上述方法移植到ii中，会因为重复元素过多而导致TLE，因此ii和iii要区分对待。
