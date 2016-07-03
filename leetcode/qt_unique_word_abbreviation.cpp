/**
* @Author: Tian Qiao
* @Date:   2016-07-03T23:51:21+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T23:52:59+08:00
*/



_______________________________________________________________________________


An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true


_______________________________________________________________________________
/*class ValidWordAbbr {
private:
    unordered_set<string> dict;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto i:dictionary) {
            if(i.size()<3) continue; // empty string and letter will not be put into dict
            //else if(i.size()<3) dict.insert(i);
            else dict.insert(i[0]+to_string(i.size()-2)+i[i.size()-1]);
        }
    }

    bool isUnique(string word) {
        if(word.size()<3) return true;
        string abbr = word[0]+to_string(word.size()-2)+word[word.size()-1];
        return dict.find(abbr)==dict.end();
    }
};*/

// MLE
/*
class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> &dictionary) {
		for (auto i:dictionary) {
			string abbr = i[0] + to_string(i.size()) + i[i.length() - 1];
			mp[abbr].insert(i);
		}
	}

	bool isUnique(string word) {
		string abbr = word[0] + to_string(word.size()) + word[word.size()-1 - 1];
		return mp[abbr].count(word) == mp[abbr].size();
	}
private:
	unordered_map<string, unordered_set<string>> mp;
};*/
class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> &dictionary) {
		for (auto i:dictionary) {
			string key = getKey(i);
			if(mp.find(key)!=mp.end()) {
			    if(mp[key]!=i) mp[key] = ""; // dictionary中不止一个单词映射到同一个key
			} else {
			    mp[key] = i;
			}
		}
	}

	bool isUnique(string word) {
		string key = getKey(word);
		return mp.find(key)==mp.end() || mp[key]==word;
	}
private:
	unordered_map<string, string> mp;
	string getKey(string str){
        if(str.size()<=2) return str;
        return str[0]+to_string(str.size()-2)+str[str.length()-1];
    }
};



// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
