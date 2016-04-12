class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> ret;
            unordered_map<string, vector<string>> hashmap;
            for(auto s : strs) {
                        string key = s;
                        sort(key.begin(), key.end());
                        if(hashmap.find(key) != hashmap.end()) {
                                        hashmap[key].push_back(s);
                                    } else {
                                                    hashmap[key] = vector<string>(1, s);
                                                }
                    }
            for(auto x : hashmap) {
                        sort(x.second.begin(), x.second.end());
                        ret.push_back(x.second);
                    }
            return ret;
        }
};
