/**
* @Author: Tian Qiao
* @Date:   2016-07-18T00:24:20+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-18T00:41:24+08:00
* @Inc: Microsoft, Google, Airbnb
* @Difficulty: Hard
* @Tag: Backtracking, Trie
*/

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
For example,
Given words = ["oath","pea","eat","rain"] and board =
[
['o','a','a','n'],
['e','t','a','e'],
['i','h','k','r'],
['i','f','l','v']
]
Return ["eat","oath"].
*/


// 1.
// https://discuss.leetcode.com/topic/33246/java-15ms-easiest-solution-100-00
/*
##### BACKTRACKING + TRIE

Intuitively, start from every cell and try to build a word in the dictionary. Backtracking (dfs) is the powerful way to exhaust every possible ways. Apparently, we need to do pruning when current character is not in any word.

How do we instantly know the current character is invalid? HashMap?
How do we instantly know what's the next valid character? LinkedList?
But the next character can be chosen from a list of characters. "Mutil-LinkedList"?
Combing them, Trie is the natural choice. Notice that:

TrieNode is all we need. search and startsWith are useless.
No need to store character at TrieNode. c.next[i] != null is enough.
Never use c1 + c2 + c3. Use StringBuilder.
No need to use O(n^2) extra space visited[m][n].
No need to use StringBuilder. Storing word itself at leaf node is enough.
No need to use HashSet to de-duplicate. Use "one time search" trie.
For more explanations, check out dietpepsi's blog.


##### CODE OPTIMIZATION
UPDATE: Thanks to @dietpepsi we further improved from 17ms to 15ms.

59ms: Use search and startsWith in Trie class like this popular solution.
33ms: Remove Trie class which unnecessarily starts from root in every dfs call.
30ms: Use w.toCharArray() instead of w.charAt(i).
22ms: Use StringBuilder instead of c1 + c2 + c3.
20ms: Remove StringBuilder completely by storing word instead of boolean in TrieNode.
20ms: Remove visited[m][n] completely by modifying board[i][j] = '#' directly.
18ms: check validity, e.g., if(i > 0) dfs(...), before going to the next dfs.
17ms: De-duplicate c - a with one variable i.
15ms: Remove HashSet completely. dietpepsi's idea is awesome.
The final run time is 15ms. Hope it helps!

*/
class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> child;
        string word;
        TrieNode() : word(""), child(vector<TrieNode*>(26, nullptr)) {}
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                int i = c - 'a';
                if (curr->child[i] == NULL) curr->child[i] = new TrieNode();
                curr = curr->child[i];
            }
            curr->word = w;
        }
        return root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> out;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); ++i)
        for(int j = 0; j < board[0].size(); ++j)
        dfs(board, i, j, root, out);
        return out;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& out) {
        char c = board[i][j];
        if(c == '#' || curr->child[c - 'a'] == NULL) return;
        curr = curr->child[c - 'a'];
        if (curr->word != "") {
            out.push_back(curr->word);
            curr->word = "";
        }
        board[i][j] = '#';
        if(i > 0) dfs(board, i - 1, j , curr, out);
        if(j > 0) dfs(board, i, j - 1, curr, out);
        if(i < board.size() - 1) dfs(board, i + 1, j, curr, out);
        if(j < board[0].size() - 1) dfs(board, i, j + 1, curr, out);
        board[i][j] = c;
    }
};


// 2. Trie+Backtracking (48ms)
// https://discuss.leetcode.com/topic/14301/my-c-trie-backtrace-based-solution-48-ms/2

// The idea is to use a Trie to build a prefix tree for words to simplify the search and do DFS to search all the possible strings.
// or Trie, 26 pointers to point the sub-strings and a bool leaf to indicate whether the current node is a leaf (i.e. a string in words) and also idx is used to save the index of words for the current node.
// For DFS, just check if the current position is visited before (board[i][j]=='X'), if so, return, check if there is a string with such prefix (nullptr == root->children[words[idx][pos]-'a']), if not, return; otherwise, check if the current searched string is a leaf of the trie (a string in words), if so, save it to res and set leaf of the trie node to false to indicate such string is already found. At last, move to its neighbors to continue the search. Remember to recover the char [i][j] at the end.
// 同3
class Solution {
    class Trie{
    public:
        Trie *children[26]; // pointers to its substrings starting with 'a' to 'z'
        bool leaf; // if the node is a leaf, or if there is a word stopping at here
        int idx; // if it is a leaf, the string index of the array words
        Trie()
        {
            this->leaf = false;
            this->idx = 0;
            fill_n(this->children, 26, nullptr);
        }
    };

public:
    void insertWords(Trie *root, vector<string>& words, int idx)
    {
        int pos = 0, len = words[idx].size();
        while(pos<len)
        {
            if(nullptr == root->children[words[idx][pos]-'a']) root->children[words[idx][pos]-'a'] = new Trie();
            root = root->children[words[idx][pos++]-'a'];
        }
        root->leaf = true;
        root->idx = idx;
    }

    Trie *buildTrie(vector<string>& words)
    {
        Trie *root = new Trie();
        int i;
        for(i=0; i<words.size();i++) insertWords(root, words, i);
        return root;
    }

    void checkWords(vector<vector<char>>& board, int i, int j, int row, int col, Trie *root, vector<string> &res, vector<string>& words)
    {
        char temp;
        if(board[i][j]=='X') return; // visited before;
        if(nullptr == root->children[board[i][j]-'a']) return ; // no string with such prefix
        else
        {
            temp = board[i][j];
            if(root->children[temp-'a']->leaf)  // if it is a leaf
            {
                res.push_back(words[root->children[temp-'a']->idx]);
                root->children[temp-'a']->leaf = false; // set to false to indicate that we found it already
            }
            board[i][j]='X'; //mark the current position as visited
            // check all the possible neighbors
            if(i>0) checkWords(board, i-1, j, row, col, root->children[temp-'a'], res, words);
            if((i+1)<row) checkWords(board, i+1, j, row, col,  root->children[temp-'a'], res, words);
            if(j>0) checkWords(board, i, j-1,  row, col, root->children[temp-'a'], res, words);
            if((j+1)<col)  checkWords(board, i, j+1,  row, col, root->children[temp-'a'], res, words);
            board[i][j] = temp; // recover the current position
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int row = board.size();
        if(0==row) return res;
        int col = board[0].size();
        if(0==col) return res;
        int wordCount = words.size();
        if(0==wordCount) return res;

        Trie *root = buildTrie(words);

        int i,j;
        for(i =0 ; i<row; i++)
        {
            for(j=0; j<col && wordCount > res.size(); j++)
            {
                checkWords(board, i, j, row, col, root, res, words);
            }
        }
        return res;
    }
};

// 3. Add TreeNode counter, helps not much
class Solution {
private:
    class Trie {
    public:
        Trie * children[26];
        bool isLeaf;
        int  wordIdx;
        int prefixCount;

        Trie() {
            isLeaf = false;
            wordIdx = 0;
            prefixCount = 0;
            fill_n(children, 26, nullptr);
        }

        ~Trie() {
            for(auto i=0; i<26; ++i) delete children[i];
        }
    };
    void insertWord(Trie *root,  const vector<string>& words, int idx) {
        int i, childID, len = words[idx].size();
        for(i=0, root->prefixCount++ ; i<len; ++i)
        {
            childID = words[idx][i]-'a';
            if(!root->children[childID]) root->children[childID] = new Trie();
            root = root->children[childID];
            ++root->prefixCount;
        }
        root->isLeaf = true;
        root->wordIdx = idx;
    }

    Trie *buildTrie(const vector<string> &words) {
        Trie *root = new Trie();
        for(int i=0; i < words.size(); ++i) insertWord(root, words, i);
        return root;
    }

    int dfs_Trie(vector<string> &res, Trie *root, vector<vector<char>>& board, vector<string>& words, int row, int col) {
        int detected = 0;

        if(root->isLeaf)
        {
            ++detected;
            root->isLeaf = false;
            res.push_back(words[root->wordIdx]);
        }

        if( row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]=='*' || !root->children[ board[row][col]-'a'] || root->children[ board[row][col]-'a']->prefixCount <= 0 ) return detected;
        int curC = board[row][col] - 'a';
        board[row][col] = '*';
        detected += dfs_Trie(res, root->children[curC], board, words, row-1, col) +
        dfs_Trie(res, root->children[curC], board, words, row+1, col) +
        dfs_Trie(res, root->children[curC], board, words, row, col - 1) +
        dfs_Trie(res, root->children[curC], board, words, row, col + 1) ;
        root->prefixCount -=detected;
        board[row][col] = curC+'a';
        return detected;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int M, N, wordNum = words.size();
        vector<string> res;
        if( !(M = board.size()) || !(N = board[0].size()) || !wordNum) return res;
        Trie *root = buildTrie(words);
        for(auto i=0; i<M && root->prefixCount; ++i)
        for(auto j=0; j<N; ++j)
        dfs_Trie(res, root, board, words, i, j);
        delete root;
        return res;
    }
};
