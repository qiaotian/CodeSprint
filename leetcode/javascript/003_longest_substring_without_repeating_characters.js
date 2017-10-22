/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/


/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    /*
    var ans = 0;  // max substring length
    var bgn = 0;  // the starting index of the current substring
    var map = {};
    for (var i=0; i < s.length; i++) {
        if (map[s[i]] == "undefined") {
            ans = Math.max(ans, i - bgn + 1)
        } else {
            bgn = map[s[i]] + 1; // mv the starting index to next of repeating char
        }
        map[s[i]] = i;
    }
    return ans;*/
    var ans = 0;
    var sub = "";
    for (var i = 0; i < s.length; i++) {
        var idx = sub.indexOf(s[i]);
        if (idx != -1) {
            // s[i] is repeated, then remove the repeated char and chars before.
            sub = sub.slice(idx+1);
        }
        sub = sub.concat(s[i]);
        ans = Math.max(ans, sub.length);
    }
    return ans;
};
