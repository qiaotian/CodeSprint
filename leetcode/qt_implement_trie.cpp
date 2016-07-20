/**
* @Author: Tian Qiao
* @Date:   2016-07-18T00:45:44+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-18T00:45:55+08:00
* @Inc: Google, Uber, Facebook. Bloomberg, Twitter
*/



/*
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

// 使用unordered_map存储子节点
// beats 10% bad
class TrieNode {
public:
    // Initialize your data structure here.
    char val;
    bool isend;
    unordered_map<char, TrieNode*> children;
    TrieNode(): val(' '), isend(false){}
    TrieNode(char val, bool isend):val(val), isend(isend) {}
    ~TrieNode() {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++) {
            auto search = cur->children.find(word[i]);
            if(search != cur->children.end()) {
                cur = cur->children[word[i]];
            } else {
                TrieNode* tmp = new TrieNode(word[i], false);
                cur->children[word[i]] = tmp;
                cur = tmp;
            }
            if(i==word.size()-1) cur->isend = true;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *tmp = root;
        for(int i=0; i<word.size(); i++) {
            auto search = tmp->children.find(word[i]);
            //if(word=="a") cout << search->first << " " << search->second->isend << endl;
            if(search==tmp->children.end()) return false;
            else {
                if(i==word.size()-1) {
                    if(search->second->isend == false) return false;
                    else return true;
                }
                tmp = search->second;
            }
        }
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for(int i=0; i<prefix.size(); i++) {
            auto search = tmp->children.find(prefix[i]);
            if(search==tmp->children.end()) return false;
            else tmp = search->second;
        }
        return true;
    }

private:
    TrieNode* root;
};


// 使用指针数组存储子节点
// beats 96%
class TrieNode {
public:
    TrieNode *next[26];
    bool is_word;

    // Initialize your data structure here.
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i) {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }

private:
    TrieNode* find(string key) {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
