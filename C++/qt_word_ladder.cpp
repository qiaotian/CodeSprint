/*
//BFS， two-end method
//traverse the path simultaneously from start node and end node, and merge in the middle
//the speed will increase (logN/2)^2 times compared with one-end method
int ladderLength(string start, string end, unordered_set<string> &dict) {
    unordered_set<string> begSet, endSet, *set1, *set2;
    begSet.insert(start);
    endSet.insert(end);
    int h=1, K=start.size();
    while(!begSet.empty()&&!endSet.empty()){
        if(begSet.size()<=endSet.size()){   //Make the size of two sets close for optimization
            set1=&begSet;   //set1 is the forward set
            set2=&endSet;   //set2 provides the target node for set1 to search
        }
        else{
            set1=&endSet;
            set2=&begSet;
        }
        unordered_set<string> itmSet;   //intermediate Set
        h++;
        for(auto i=set1->begin();i!=set1->end();i++){
            string cur=*i;
            for(int k=0;k<K;k++){   //iterate the characters in string cur
                char temp=cur[k];
                for(int l=0;l<26;l++){  //try all 26 alphabets
                    cur[k]='a'+l;
                    auto f=set2->find(cur);
                    if(f!=set2->end())return h;
                    f=dict.find(cur);
                    if(f!=dict.end()){
                        itmSet.insert(cur);
                        dict.erase(f);
                    }
                }
                cur[k]=temp;
            }
        }
        swap(*set1, itmSet);
    }
    return 0;
}
*/

// 2nd solution (bad)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);
        queue<string> toVisit;
        int dist = 2;
        addNextWords(beginWord, wordDict, toVisit);
        while(!toVisit.empty()) {
            int num = toVisit.size();
            for(int i = 0; i < num; i++) {
                string tmp = toVisit.front();
                toVisit.pop();
                if(tmp == endWord) return dist;
                addNextWords(tmp, wordDict, toVisit);
            }
            dist++;
        }
    }
private:
    // fuction: 
    // 1. add neighbours of word to toVisit and 
    // 2. romove word from wordDict
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        // add neighour node into the toVisit
        wordDict.erase(word);
        for(int i = 0; i < (int)word.size(); i++) {
            char oriChar = word[i];
            // construct a word
            for(int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if(wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = oriChar;
        }
        
        //TLE
        //for(auto it = wordDict.begin(); it != wordDict.end();) {
            //string tmp = *it;
            
        //    int diffCnt = 0;
        //    for(int i = 0; i < word.size(); i++) {
        //        if((*it)[i] != word[i]) diffCnt++;
        //    }
            
        //    if(diffCnt == 1) {
        //        toVisit.push(*it);
        //        it = wordDict.erase(it);
        //    } else {
        //        it++;
        //    }
        //}
    }
};

// 3rd solution
/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail; 
                ptail = &head;
            }
            unordered_set<string> temp; 
            for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
                string word = *itr;
                wordDict.erase(word);
                for (int p = 0; p < (int)word.length(); p++) {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) {
                        word[p] = 'a' + k;
                        if (ptail -> find(word) != ptail -> end())
                            return dist;
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            dist++;
            swap(*phead, temp);
        }
        return 0; 
    }
}; 
*/
/**
 * 2nd solution: BFS (bad)
 *   addNextWords may add duplicated words into toVisit, eg, Start word is connected with
 * B and C, moreover, B is connected to C. When we visit start word, B and C are pushed 
 * into queue. Then, we push C again when visiting B, which results in its slowness.
 * 
 * 3rd solution: BFS (good)
 *   use two-end search
 * 
 * REFERENCE
 * https://leetcode.com/discuss/42006/easy-76ms-c-solution-using-bfs
 * /
