// 1st Solution (too slow)
/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, char> l2r; // map from left to right
        map<char, char> r2l; // map from right to left
        
        for(int i=0; i<s.size(); i++) {
            auto searchl = l2r.find(s[i]);
            auto searchr = r2l.find(t[i]);
            if(searchl == l2r.end() && searchr == r2l.end()) {
                l2r.insert(pair<char, char>(s[i], t[i]));
                r2l.insert(pair<char, char>(t[i], s[i]));
                continue;
            }
            if(searchl != l2r.end() && searchr != r2l.end()){
                if(searchl->second == searchr->first && searchl->first == searchr->second) continue;
            }
            
            return false;
        }
        return true;
    }
};
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0};
        
        for (int i = 0; i < s.size(); ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        
        return true;
    }
};

/**
 * Since s and t are bidiretional mapping, we can map both s and t
 * to a distinguishbale system, integer for example.
 * 
 * 1st Solution use bidiretional mapping that is a little complex than the 2nd one,
 * meanwhile the 2nd one is much faster than the first one.
 * /
