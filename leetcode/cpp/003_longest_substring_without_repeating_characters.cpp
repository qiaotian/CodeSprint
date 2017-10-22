/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*int str_len=0;

        int str_size = s.size();
        int substr_len = 1;  // store the length of longest substring
        int start_idx = 1;   // the index of first element to be compared

        for(int i=0; i<str_size; ++i) {
            start_idx = i+substr_len;
            substr_len = substr_len>1?(substr_len--):1;

            // expand the substring
            for(int j=start_idx; j<str_size; ++j) {
                bool repeat = false;
                // find wether exists the repeative element
                for(int k=j-1; k>=i; k--){
                    if(s.at(k)==s.at(j)) {
                        repeat = true;
                        break;
                    }
                }
                if(repeat) break;
                substr_len++;
            }
            str_len = substr_len>str_len?substr_len:str_len;

            // terminate condition
            if(i+str_len == str_size) break;
        }
        return str_len;*/
        /*
        int a[256]={0};
        int len = s.size();
        int result = 0, max = 0;
        int temp = 0, low =0;
        for(int i =0; i < len; ++i)
        {
            temp = a[s[i]];
            if(temp)
            {
                for(int j = low; j < temp-1;j++)
                {
                    a[s[j]] = 0;
                }
                result -= temp-low-1;
                low = temp;
                a[s[i]] = i+1;
            }
            else
            {
                a[s[i]] = i+1;
                if(++result > max)
                    max = result;
            }
        }
        return max;
        */
        /*if(s.size()<2) return s.size();

        char counters[130] = {0};
        int len = 0,    // current length
            max = 0,    // longest length
            tail = 0;   // index for latest repective character

        for(int i=0; i<s.size(); ++i) {
            len++; // important
            if(counters[s.at(i)]==0) {
                // this character never shows up
                counters[s.at(i)]++;
            } else {
                // this character shows up already
                counters[s.at(i)]++;
                while(tail<i && s.at(tail)!=s.at(i)) {
                    len--;
                    counters[s.at(tail++)]--;
                }
                len--;
                counters[s.at(tail++)]--;
            }
            max=len>max?len:max;
        }
        return max;*/

        string subs = "";
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            size_t at = subs.find(s[i]);
            if ( at != string::npos) {
                subs.erase(0, at+1); // delete substring, that starting from 0, len is at+1. if at+1 is bigger than str len, then, the entire string is erased
            }
            subs += s[i];
            res = subs.size() > res ? subs.size() : res; // res = max(res, subs.size())
        }
        return res;
    }
};

// NOTICE:
// converting string to char[] does not make it faster, which
// could have two commonly used method:
//   1. string.c_str(); 2. string.data(): only the first one returns content ending with '\0'
// string could contain any char which is not just "A~Z" or "a~z"
