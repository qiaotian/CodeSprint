/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-10T01:32:39+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-10T02:10:53+08:00
* @Inc: Google
* @Difficulty: Medium
*/



/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.
For example,
Given n = 2, return ["11","69","88","96"].
*/


// beat 20% bad
class Solution {
public:
    int N = INT32_MIN;
    vector<string> findStrobogrammatic(int n) {
        N = max(N, n);
        vector<string> ans;
        if(n==0) return vector<string>(1, "");
        if(n==1) return vector<string>{"0","1","8"}; // 0 1 8
        vector<string> tmp = findStrobogrammatic(n-2);
        for(auto i:tmp) {
            if(i.size()!=N-2) {
                cout << i.size() << endl;
                ans.push_back("0"+i+"0");
            }
            ans.push_back("1"+i+"1");
            ans.push_back("6"+i+"9");
            ans.push_back("8"+i+"8");
            ans.push_back("9"+i+"6");
        }
        return ans;
    }
};

// beat 50%, but almost the same code
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n , n);
    }
    vector<string> helper(int m, int n){
        if(m == 0) return vector<string>({""});
        if(m == 1) return vector<string>({"0", "1", "8"});
        vector<string> tmp = helper(m - 2, n), res;
        for(int i = 0; i < tmp.size(); i++){
            if(m != n) res.push_back("0" + tmp[i] + "0");
            res.push_back("1" + tmp[i] + "1");
            res.push_back("6" + tmp[i] + "9");
            res.push_back("8" + tmp[i] + "8");
            res.push_back("9" + tmp[i] + "6");
        }
        return res;
    }
};
