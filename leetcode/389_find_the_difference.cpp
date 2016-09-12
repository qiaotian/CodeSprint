/*
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for(auto c:s) cnt[c-'a']++;
        for(auto c:t) {
            cnt[c-'a']--;
            if(cnt[c-'a']<0) return c;
        }
        return '0'; // 
    }
};

class Solution {
public:
	char findTheDifference(string s, string t) {
		char ans = 0;
		for(auto c:s) ans^=c;
		for(auto c:s) ans^=c;
		return ans;
	}
}
