int soluton(vector<int>& A) {
    unordered_set<int> hash;
    for(auto i:A) {
        if(hash.find(i) == hash.end()) hash.insert(i);
    }
    return hash.size();
}

// find多余了
// 直接插入

int soluton(vector<int>& A) {
    unordered_set<int> hash;
    for(auto i:A) {
        hash.insert(i);
    }
    return hash.size();
}
