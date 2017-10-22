class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int count = pow(2, n);
        for(int i = 0; i < count; i++) {
            res.push_back((i>>1)^i);
        }
        return res;
    }
};

/**
 * G(N) = (B(n)/2) XOR B(n)
 * https://zh.wikipedia.org/wiki/格雷码
 * /
