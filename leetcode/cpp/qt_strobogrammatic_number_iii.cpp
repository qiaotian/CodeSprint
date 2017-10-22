/**
* @Author: Tian Qiao
* @Date:   2016-08-04T01:18:17+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-04T01:18:19+08:00
* @Tag: Math, Recursion
*/


/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
Note:
Because the range might be a large number, the low and high numbers are represented as string.
*/

// 1 超级慢
// https://discuss.leetcode.com/topic/22007/c-accepted-solution
class Solution {
public:
    bool compare(string s1, string s2) {
    	if (s1.length() != s2.length())
    		return s1.length() <= s2.length();

    	for (int i = 0; i < s1.length(); i++) {
    		if (s1[i] < s2[i]) return true;
    		else if (s1[i] > s2[i]) return false;
    	}

    	return true;
    }

    int strobogrammaticInRange(const vector<pair<char, char>>& nums, const string& low, const string& high, string t, int cnt) {
    	if (high.length() < t.length())
    		return cnt;
    	if (compare(low, t) && compare(t, high))
    		if (t.length() == 1 || t.length() > 1 && t.front() != '0')
    			cnt++;

    	for (auto iter = nums.begin(); iter != nums.end(); ++iter)
    		cnt = strobogrammaticInRange(nums, low, high, string(1, iter->first) + t + string(1, iter->second), cnt);

    	return cnt;
    }

    int strobogrammaticInRange(string low, string high) {
    	if (!compare(low, high)) return 0;

    	vector<pair<char, char>> nums = { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' } };

    	int cnt = strobogrammaticInRange(nums, low, high, "", 0);
    	cnt = strobogrammaticInRange(nums, low, high, "0", cnt);
    	cnt = strobogrammaticInRange(nums, low, high, "1", cnt);
    	cnt = strobogrammaticInRange(nums, low, high, "8", cnt);

    	return cnt;
    }
};


// 2
// https://discuss.leetcode.com/topic/24688/16ms-c-solution
// The idea is to cut a value from the left of the string and then for each of operations '+', '-', '*' repeat the procedure recursively. The trick is to pass the sum of all left summands and the product of rightmost factors. This allows to calculate the left sum and the right product on the next step depending on the next chosen operation.
class Solution {
    typedef long long int i64;

    string myS;
    const char* s;
    i64 target;
    int slen;

public:

    vector<string> addOperators(const string& num, int t) {
        myS = num;
        slen = myS.size();
        s = myS.c_str();
        target = t;

        vector<string> res;
        char buf[slen*2+1];

        int lmax = (s[0] == '0' ? 1 : slen);
        i64 v = 0;
        for (int l=1; l<=lmax; ++l) {
            int c = s[l-1];
            v = v*10 + (c-'0');   // add next digit
            buf[l-1] = c;  // only need to append the last digit
            processTail(0, v, l, buf, l, res);
        }
        return res;
    }

    void processTail(i64 prevsum, i64 last, int pos, char* buf, int bufpos, vector<string>& res) {
        if (pos == slen) {
            // end of string
            // check the value and save
            if (prevsum+last == target) {
                buf[bufpos] = 0;
                res.push_back(buf);
            }
            return;
        }

        int lmax = (s[pos] == '0' ? 1 : slen-pos); // don't allow multichar intergers starting from a '0'
        i64 v = 0;
        for (int l=1; l<=lmax; ++l) {
            int c = s[pos+l-1];
            v = v*10 + (c-'0');     // add next digit to v

            buf[bufpos] = '+';
            buf[bufpos+l] = c;      // only need to append the last digit of v
            processTail(prevsum+last, v, pos+l, buf, bufpos+l+1, res);

            buf[bufpos] = '-';
            processTail(prevsum+last, -v, pos+l, buf, bufpos+l+1, res);

            buf[bufpos] = '*';
            processTail(prevsum, last*v, pos+l, buf, bufpos+l+1, res);
        }
    }
};
