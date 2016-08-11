/*
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

//超时
/*
class Solution {
public:
    bool isPalindrome(string a) {
        int lf = 0;
        int rt = a.size()-1;
        while(lf<rt && a[lf]==a[rt]) {
            lf++;
            rt--;
        }
        return a[lf]==a[rt];
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        
        int n = words.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(isPalindrome(words[i]+words[j])) {
                    ret.push_back(vector<int>{i,j});
                }
            }
        }
        
        return ret;
    }
};
*/

class Solution {
public:
    bool isPalindrome(string str){
        int i = 0;
        int j = str.size() - 1; 

        while(i < j) {
            if(str[i++] != str[j--]) return false;
        }

        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        unordered_map<string, int> dict;
        
        for(int i=0; i<words.size(); i++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        
        
        // 找到所有{"", string} 和 {string, ""}
        if(dict.find("") != dict.end()) {
            // 存在空字符串
            // 不能删除空字符串，因为会改变 空串 后面的string的序号
            for(int i=0; i<words.size(); i++) {
                if(i==dict[""]) continue;
                if(isPalindrome(words[i])) {
                    ret.push_back(vector<int>{i, dict[""]});
                    ret.push_back(vector<int>{dict[""], i});
                }
            }
        }
        
        
        // 找到所有 {string, string}
        for(int i=0; i<words.size(); i++) {
            if(words[i].size() < 1) continue;
            
            for(int j=1; j<=words[i].size(); j++) {
                // divide the words[i] into two substrings
                string left = words[i].substr(0, j); // left string不能为空字符串
                string right = words[i].substr(j, words.size()-j); // right string 可能为空
                
                if(dict.find(left)!=dict.end() && isPalindrome(right)  && i!=dict[left]) {
                    // i!=dict[left]: 当word[i]为回文，且left为word[i]时，搜索结果会是word[i]本身
                    ret.push_back(vector<int>{i, dict[left]});
                }
                if(dict.find(right)!=dict.end() && isPalindrome(left) && dict[right]!=i && right.size()) {
                    ret.push_back({dict[right], i});
                }
            }
        }
        
        return ret;
    }
};
