/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-08T12:42:57+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-08T13:23:28+08:00
*/



This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.


// beats 78% good
class WordDistance {
public:
unordered_map<string, vector<int>> dict;
    WordDistance(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            dict[words[i]].push_back(i);
            /*if(dict.find(words[i])!=dict.end()) {
                dict[words[i]].push_back(i);
            } else {
                dict.insert({words[i], vector<int>(1,i)});
            }*/
        }
    }

    int shortest(string word1, string word2) {
        vector<int>& pos1 = dict[word1]; // #1
        vector<int>& pos2 = dict[word2];
        /*
        for(auto i: pos1) cout << i<< " ";
        cout << endl;
        for(auto i: pos2) cout << i<< " ";
        cout << endl;
        */
        int idx1 = 0, idx2 = 0;
        int dist = INT32_MAX;
        while(idx1<pos1.size() && idx2<pos2.size()) {
            dist = min(dist, abs(pos1[idx1]-pos2[idx2]));
            if(idx1==pos1.size()-1 && pos1[idx1]<=pos2[idx2]) break;
            if(idx2==pos2.size()-1 && pos2[idx2]<=pos1[idx1]) break;

            if(pos1[idx1]<pos2[idx2]) idx1++;
            else idx2++;
        }
        return dist;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
