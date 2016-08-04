/**
* @Author: Tian Qiao
* @Date:   2016-08-04T15:23:03+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-04T15:23:07+08:00
* @Inc: Google
* @Difficulty: Hard
* @Difficulty: Hash Table, String
*/

/**
Given a string, find the length of the longest substring T that contains at most k distinct characters.
For example, Given s = “eceba” and k = 2,
T is "ece" which its length is 3.
*/

// 1. AC but it's not right
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if(k==0 || n==0) return 0;

        int ans = INT32_MIN;
        int start = 0; // 子串起点
        int distinctCnt = 0; //子串中互异字符数目
        vector<int> cnt(128, 0); // 子串中各互异字符的数目
        for(int i=0; i<n; i++) {
            cnt[s[i]]++;
            //if(cnt[s[i]]==1) {
            distinctCnt+=cnt[s[i]]==1;
            while(distinctCnt>k && start<=i) {
                if(--cnt[s[start++]]==0) distinctCnt--;
            }
            //}
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};

// 2. Use a Hash Table and a Vector
// https://discuss.leetcode.com/topic/53200/c-solution-using-hashmap-and-vector-idea-sharing
class RandomizedSet {
private:
    vector<int> tmp;
    unordered_map<int, int> map;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end()) return false;
        tmp.emplace_back(val);
        map[val] = tmp.size() - 1;
        return true;
    }

    /** Deletes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end()) return false;
        int indx = map[val];
        tmp[indx] = tmp[tmp.size() - 1];
        map[tmp[indx]] = indx;
        tmp.pop_back();
        map.erase(map.find(val));
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return tmp[rand() % tmp.size()];
    }
};
