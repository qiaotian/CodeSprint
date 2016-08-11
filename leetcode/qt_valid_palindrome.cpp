/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        // 1st Solution (Beats 11%)
        /*
        int l = 0, r = s.size()-1;
        
        while(l<=r) {
            while(!((s[l]<='Z'&&s[l]>='A') || (s[l]<='z'&&s[l]>='a') || (s[l]<='9'&&s[l]>='0')) && l<r) l++;
            while(!((s[r]<='Z'&&s[r]>='A') || (s[r]<='z'&&s[r]>='a') || (s[r]<='9'&&s[r]>='0')) && l<r) r--;
        
            if(l>=r) return true;
        
            if(((s[l]<='Z' && s[l] >='A') || (s[l]<='z' && s[l] >='a')) &&
               ((s[r]<='Z' && s[r] >='A') || (s[r]<='z' && s[r] >='a'))) {
                if(s[l]==s[r] || s[l]+32==s[r] || s[l]-32==s[r]) {
                    l++;
                    r--;
                    continue;
                }
            }
        
            if((s[l]<='9'&&s[l]>='0') && (s[r]<='9'&&s[r]>='0')) {
                if (s[l]==s[r]) {
                    l++;
                    r--;
                    continue;
                }
            }
        
            return false;
        }
        
        return true; // s = ""
        */
        
        // 2nd Solution ()
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { 
            // Move 2 pointers from each end until they collide
            while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
            while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
        }

        return true;
    }
};
