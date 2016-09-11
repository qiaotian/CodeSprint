/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/


// T: O(2N) S: O(N)
class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        if(s.empty()) return ans;
        
        vector<int> dp(26, 0);
        
        int n = s.size();
        for(int i=0; i<n; i++) {
            dp[s[i]-'a']++;
        }
        for(int i=0; i<n; i++) {
            if(dp[s[i]-'a']==1) return i;
        }
        return ans;
    }
};


// T: O(2N) S: O(1)
class Solution {
public:
    int firstUniqChar(string s) {
		int one = 0, two = 0;
        for(auto c:s) {
            int bit = 1 << c - 97;
            if(!(one & bit))
                if(two & bit)
                    one |= bit;
                continue;

            one &= ~bit;
            two |= bit;
		}
        for(auto c:s){
            bit = 1 << c - 97;
            if one & bit:
                return i;
        }
        return -1;
	}
}
