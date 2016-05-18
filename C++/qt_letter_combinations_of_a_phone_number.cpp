class Solution {
private:
    vector<vector<char>> hash;
public:
    Solution() : hash(10, vector<char>(0)) {}

    void initHash() {
        hash[2].push_back('a');
        hash[2].push_back('b');
        hash[2].push_back('c');
        hash[3].push_back('d');
        hash[3].push_back('e');
        hash[3].push_back('f');
        hash[4].push_back('g');
        hash[4].push_back('h');
        hash[4].push_back('i');
        hash[5].push_back('j');
        hash[5].push_back('k');
        hash[5].push_back('l');
        hash[6].push_back('m');
        hash[6].push_back('n');
        hash[6].push_back('o');
        hash[7].push_back('p');
        hash[7].push_back('q');
        hash[7].push_back('r');
        hash[7].push_back('s');
        hash[8].push_back('t');
        hash[8].push_back('u');
        hash[8].push_back('v');
        hash[9].push_back('w');
        hash[9].push_back('x');
        hash[9].push_back('y');
        hash[9].push_back('z');
    }
    void helper(string& digits, int pos, vector<string>& ans, string tmp) {
        if(pos>=digits.size()) {
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<hash[digits[pos]-'0'].size(); i++) {
            helper(digits, pos+1, ans, tmp+hash[digits[pos]-'0'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;

        initHash();
        helper(digits, 0, ans, "");
        return ans;
    }
};
