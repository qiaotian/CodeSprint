class TrieNode {
public:
    bool iskey;
    TrieNode* child[26];
    TrieNode(): iskey(false) {
        memset(child, NULL, sizeof(TrieNode*) * 26);
    };
};


class WordDictionary {
private:
    TrieNode *root;
    bool query(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (run && word[i] != '.')
                run = run -> child[word[i] - 'a'];
            else if (run && word[i] == '.') { 
                TrieNode* tmp = run;
                for (int j = 0; j < 26; j++) {
                    run = tmp -> child[j];
                    if (query(word + i + 1, run))
                        return true;
                }
            }
            else break;
        }
        return run && run->iskey; 
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *ptr = root;
        for(char c : word) {
            if(!ptr->child[c-'a']) ptr->child[c-'a'] = new TrieNode();
            ptr = ptr->child[c-'a'];
        }
        ptr->iskey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word.c_str(), root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

/**
 * 字典树
 * https://leetcode.com/discuss/39022/80ms-clear-c-code-with-detailed-explanations
 * /
