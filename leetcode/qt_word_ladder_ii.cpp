/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

// 1st Time Limit Exceeded
/*
class Solution {
private:
    vector<vector<string>> paths; // store the all pathes from beginword to endword
    map<string, multiset<string>> edges; // map a single word to several words
    int shortestlen = INT32_MAX;
    
    bool judgeNeighbour(string str1, string str2) {
        int diffCnt = 0;
        for(int i=0; i<str1.size(); i++) if(str1[i]!=str2[i]) diffCnt++;
        return diffCnt==1;
    }
    
    // return the shortest path length, if does not exist, return -1
    void findBegin2End(string beginWord, string endWord, map<string, bool>& flag, vector<string>& currentPath) {
        if(beginWord == endWord) {
            if (currentPath.size() < shortestlen) shortestlen = (int)currentPath.size();
            paths.push_back(currentPath);
            return;
        }
        if(edges[beginWord].size()==0) return;
    
        if(currentPath.size() >= shortestlen) return; // overlength
    
        for(auto i = edges[beginWord].begin(); i != edges[beginWord].end(); i++) {
            if (flag[*i]) continue;
        
            flag[*i] = true;
            currentPath.push_back(*i);
            findBegin2End(*i, endWord, flag, currentPath);
            currentPath.pop_back();
            flag[*i] = false;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        int shortest = INT32_MAX;
        
        wordList.insert(beginWord);
        wordList.insert(endWord);
        
        // prepare for the flags
        map<string, bool> flag;
        for(auto i = wordList.begin(); i!=wordList.end(); i++) {
            flag.insert(make_pair(*i, false));
        }
        
        // prepare for the edges
        for(auto i = wordList.begin(); i!=wordList.end(); i++) {
            multiset<string> mset;
            for(auto j = wordList.begin(); j!=wordList.end(); j++) {
                if(judgeNeighbour(*i, *j)) {
                    mset.insert(*j);
                }
            }
            edges.insert(make_pair(*i, mset));
        }
        
        // find all paths
        vector<string> currentpath;
        flag[beginWord] = true;
        currentpath.push_back(beginWord);
        findBegin2End(beginWord, endWord, flag, currentpath);
        currentpath.pop_back();
        flag[beginWord] = false;
        
        // delete the nonshortest pathes
        for(auto i = paths.begin(); i!= paths.end();) {
            if((*i).size() > shortest) paths.erase(i);
            else i++;
        }
        return paths;
    }
};
*/

// 2nd solution

class Solution {
public:
    std::vector<std::vector<std::string> > findLadders(std::string beginWord, std::string endWord, std::unordered_set<std::string> &dict) {
        std::vector<std::vector<std::string> > paths;
        std::vector<std::string> path(1, beginWord);
        if (beginWord == endWord) {
            paths.push_back(path);
            return paths;
        }
        std::unordered_set<std::string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        std::unordered_map<std::string, std::vector<std::string> > nexts;
        bool words1IsBegin = false;
        if (findLaddersHelper(words1, words2, dict, nexts, words1IsBegin))
            getPath(beginWord, endWord, nexts, path, paths);
        return paths;
    }
private:
    bool findLaddersHelper(
        std::unordered_set<std::string> &words1,
        std::unordered_set<std::string> &words2,
        std::unordered_set<std::string> &dict,
        std::unordered_map<std::string, std::vector<std::string> > &nexts,
        bool &words1IsBegin) {
        words1IsBegin = !words1IsBegin;
        if (words1.empty())
            return false;
        if (words1.size() > words2.size())
            return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
        for (auto it = words1.begin(); it != words1.end(); ++it)
            dict.erase(*it);
        for (auto it = words2.begin(); it != words2.end(); ++it)
            dict.erase(*it);
        std::unordered_set<std::string> words3;
        bool reach = false;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            std::string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                    if (*ch != tmp)
                        if (words2.find(word) != words2.end()) {
                            reach = true;
                            words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                        else if (!reach && dict.find(word) != dict.end()) {
                            words3.insert(word);
                            words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                *ch = tmp;
            }
        }
        return reach ? true : findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
    }
private:
    void getPath(
        std::string beginWord,
        std::string &endWord,
        std::unordered_map<std::string, std::vector<std::string> > &nexts,
        std::vector<std::string> &path,
        std::vector<std::vector<std::string> > &paths) {
        if (beginWord == endWord)
            paths.push_back(path);
        else
            for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
                path.push_back(*it);
                getPath(*it, endWord, nexts, path, paths);
                path.pop_back();
            }
    }
};
